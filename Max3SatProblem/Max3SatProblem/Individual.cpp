#include "Individual.h"

#include <iostream>
#include <ostream>

using namespace std;

Individual::Individual() : amount_(0)
{
	
}


Individual::Individual(int size) : amount_(size)
{
	
}

int Individual::fitness(const Max3SatProblem& problem)
{
	return problem.compute(*this);

}

void Individual::crossover(const Individual& first, const Individual& second) 
{
	for (int i = 0; i < amount_; i++)
	{
		if (rand() % 2)
		{
			
			genotype_.at(i) = first.genotype_.at(i);
		}
		else
		{
			genotype_.at(i) = second.genotype_.at(i);
		}

	}

}

void Individual::mutation()
{

	const int index = rand() % amount_;

	genotype_.at(index) = (genotype_.at(index) + 1) % 2;
}

void Individual::print() const
{
	cout << "Individual: ";
	for (const bool value : genotype_)
	{
		cout << value << "  ";
	}
	cout << endl;
}

vector<bool> Individual::get_genotype()
{
	return genotype_;
}

bool Individual::get_genotype_value(int variable)
{
	return genotype_.at(variable);
}

void Individual::random_genotype()
{
	for (int i = 0; i < amount_; ++i)
	{
		bool value = rand() % 2;

		genotype_.push_back(value);
	}
}


