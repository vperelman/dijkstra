#pragma once
#include <iostream>
#include <ostream>
#include <vector>

class graph {
public:
	graph(int size, std::vector<std::vector<int>> adjacency_matrix) :size(size), adjacency_matrix(adjacency_matrix){};
	friend std::ostream& operator<< (std::ostream&, const graph&);
	std::vector<std::vector<int>> get_adjacency_matrix() { return adjacency_matrix; }
	int getSize() { return size; }
	virtual ~graph();
private:
	int size;
	std::vector<std::vector<int>> adjacency_matrix;
};

