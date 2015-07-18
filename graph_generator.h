#pragma once
#include "graph.h"
#include <memory>

class graph_generator
{
public:
	virtual std::unique_ptr<graph> generateGraph(int numOfNodes, double density) = 0;
	graph_generator();
	virtual ~graph_generator();
};

