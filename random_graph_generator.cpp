#include "random_graph_generator.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <memory>

using namespace std;


random_graph_generator::random_graph_generator()
{
}


random_graph_generator::~random_graph_generator()
{
}


unique_ptr<graph> random_graph_generator::generateGraph(int num_of_nodes, double density) {
	vector<vector<int>> matrix;
	srand(time(0));
	for (int i = 0; i < num_of_nodes; i++) {
		vector<int> row;
		for (int j = 0; j < num_of_nodes; j++) {
			if (i == j) {
				row.push_back(0);
			}
			else if (i > j) {
				row.push_back(matrix[j][i]);
			}
			else {
				if (rand() % 100 < (density * 100)) {
					row.push_back(rand() % 50);
				}
				else {
					row.push_back(-1);
				}
			}
		}
		matrix.push_back(row);
	}
	return unique_ptr<graph>(new graph(num_of_nodes, matrix));
}
