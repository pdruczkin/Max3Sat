#include <iostream>

#include "Max3SatProblem.h"
#include "Optimizer.h"

using namespace std;

int main()
{
	Optimizer optimizer(0.5, 0.1, 30);

	optimizer.load_instance("max3sat/200/m3s_200_0.txt", 200);

	const int iterations = 200;

	cout << "start" << endl;
	optimizer.find_best_result();
	optimizer.print_state();

	cout << endl << endl;

	for (int i = 0; i < iterations; i++)
	{
		cout << i << " ";

		optimizer.run_iteration();
		optimizer.find_best_result();

	}
	cout << endl;

	optimizer.find_best_result();
	optimizer.print_state();

	

	

}

