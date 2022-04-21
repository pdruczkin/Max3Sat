#pragma once
#include <string>
#include <vector>


class Individual;
using namespace std;


class Max3SatProblem
{
public:
	Max3SatProblem();
	void load(const string& file_path, int max_index);
	void print() const;

	int compute(Individual& individual) const;

private:

	vector<vector<int>> clauses_;
	int max_index_ = 0;


};
