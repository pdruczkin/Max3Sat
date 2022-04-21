#include "Optimizer.h"

#include <ctime>
#include <iostream>


Optimizer::Optimizer(const double mutation_prob, const double crossover_prob, const int population_size) :
	population_size_(population_size),
	mutation_probability_(mutation_prob),
	crossover_probability_(crossover_prob)
{

}

void Optimizer::load_instance(const string& file_path, int max_index)
{
	problem_.load(file_path, max_index);
	//problem_.print();

	initialize(max_index);
}

void Optimizer::find_best_result()
{
	int best_index = -1;
	int best_value = 0;


	for (int i = 0; i < population_size_; i++)
	{
		int value = population_.at(i).fitness(problem_);
		
		if(value > best_value)
		{
			
			best_value = value;
			best_index = i;
		}
	}

	if(best_value > best_result_value_)
	{
		cout << endl << "Change: " << best_value << endl;
		best_result_ = population_.at(best_index);
		best_result_value_ = best_value;
	}

}

void Optimizer::run_iteration()
{

	
	vector<Individual> new_population;

	while(new_population.size() < population_size_)
	{
		Individual parent1 = pick_parent(2);
		Individual parent2 = pick_parent(2);


		Individual child1 = parent1;
		Individual child2 = parent2;


		if(is_happening(crossover_probability_))
		{
			child1.crossover(parent1,parent2);
			child2.crossover(parent2,parent1);
		}


		if(is_happening(mutation_probability_))
		{
			child1.mutation();
			child2.mutation();
		}
		

		new_population.push_back(child1);
		new_population.push_back(child2);
	}

	population_ = new_population;
}

void Optimizer::print_state() const
{
	cout << "Best ";
	best_result_.print();
	cout << best_result_value_ << endl << endl;
}

void Optimizer::initialize(int max_index)
{
	srand(time(0));

	for (int i = 0; i < population_size_; i++)
	{
		population_.emplace_back(max_index);
	}

	for (int i = 0; i < population_size_; i++)
	{
		population_.at(i).random_genotype();
	}
}


Individual Optimizer::pick_parent(const int tournament_capacity)
{
	vector<int> indexes;
	for (int i = 0; i < tournament_capacity; i++)
	{
		int index = rand() % population_size_;
		indexes.push_back(index);
	}

	int best_index = indexes.at(0);
	int best_fitness = population_.at(best_index).fitness(problem_);

	for (int i = 1; i < tournament_capacity; i++)
	{
		int fitness = population_.at(i).fitness(problem_);
		if(fitness > best_fitness)
		{
			best_index = i;
			best_fitness = fitness;
		}
	}



	return population_.at(best_index);
}

bool Optimizer::is_happening(const double probability)
{
	double value = (double)(rand() % 100) / 100;
	return value <= probability;
}