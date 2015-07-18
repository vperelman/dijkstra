#pragma once
#include "graph_generator.h"
#include <memory>
class random_graph_generator :
	public graph_generator
{
public:
	random_graph_generator();
	~random_graph_generator();
	virtual std::unique_ptr<graph> generateGraph(int numOfNodes, double density);
};

