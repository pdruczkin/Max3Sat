#include "Max3SatProblem.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <cmath>

#include "Individual.h"


Max3SatProblem::Max3SatProblem() : max_index_(-1)
{
}


bool is_number_part(const char c)
{
	if (c == '-' || (int(c) > 47 && int(c) < 58)) return true;
	
	return false;
}

void Max3SatProblem::load(const string& file_path, int max_index)
{
	this->max_index_ = max_index;
	
	ifstream file(file_path);

	string line;

	while(getline(file,line))
	{
		string string_number;
		vector <int> clause;

		for(int i = 2; i < line.length() - 2; i++)
		{
			if(is_number_part(line[i]))
			{
				string_number += line[i];
			}
			else
			{
				int number = stoi(string_number);
				string_number = "";
				i++;
				clause.push_back(number);
			}
		}
		clauses_.push_back(clause);
	}

	if (!clauses_.empty()) cout << "pobrano" << endl;
	else cout << "błąd przy pobieraniu" << endl;


}

void Max3SatProblem::print() const
{

	for (int i = 0; i < clauses_.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << clauses_[i][j] << " ";
		}
		cout << endl;
	}
		
}

int Max3SatProblem::compute(Individual &individual) const
{
	int sum = 0;

	for (int i = 0; i < clauses_.size(); i++)
	{
		bool is_fulfilled = false;
		for (int j = 0; j < 3; j++)
		{
			int number = clauses_[i][j];
			bool value = individual.get_genotype_value(abs(number));
			if (number < 0) value = !value;
			
			if (value) is_fulfilled = true;
		}

		if (is_fulfilled) sum++;
	}



	return sum;
}
