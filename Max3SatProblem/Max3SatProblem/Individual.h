#pragma once
#include <vector>

#include "Max3SatProblem.h"


using namespace std;

class Individual
{
public:
	
	Individual();
	Individual(int size);

	int fitness(const Max3SatProblem& problem);

	void crossover(const Individual& first, const Individual& second);
	void mutation();
	

	void print() const;

	vector<bool> get_genotype();
	bool get_genotype_value(int variable);

	void random_genotype();
private:
	vector<bool> genotype_;
	int amount_;
};
