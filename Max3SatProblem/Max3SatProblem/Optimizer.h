#pragma once
#include <vector>

#include "Individual.h"
#include "Max3SatProblem.h"

using namespace std;


class Optimizer
{
public:
	Optimizer(double mutation_prob, double crossover_prob, int population_size);

	void load_instance(const string& file_path, int max_index);


	void find_best_result();

	Individual get_best_result() const { return best_result_; }

	void run_iteration();

	void print_state() const;

private:
	int population_size_;
	double mutation_probability_;
	double crossover_probability_;

	vector<Individual> population_;

	Individual best_result_;

	int best_result_value_ = 0;

	Max3SatProblem problem_;

	void initialize(int max_index);

	//algorithm
	Individual pick_parent(int tournament_capacity);

	static bool is_happening(double probability);



};



