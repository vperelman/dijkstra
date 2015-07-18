#include "graph.h"

using namespace std;

graph::~graph() {

}
ostream& operator<<(ostream& out, graph const& graph) {
	auto matrix = graph.adjacency_matrix;
	for (auto i = matrix.cbegin(); i != matrix.cend(); ++i) {
		for (auto j = i->cbegin(); j != i->cend(); ++j) {
			out << *j << " ";
		}
		out << endl;
	}

	return out;
}
