#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include "graph.h"
#include "random_graph_generator.h"

using namespace std;

class node {
private:
	int node_id;
	int total_distance;
	vector<int> path;
public:
	node(int node_id, int distance = 0, vector<int> path = vector<int>()) :node_id(node_id), total_distance(distance), path(path){};
	int get_node_id() const { return node_id; }
	int get_total_distance() const { return total_distance; }
	vector<int> get_path() { return path; }
	void set_total_distance(int distance) { total_distance = distance; }
	void add_to_path(int node) { path.push_back(node); }
	void set_path(vector<int> newpath) { path = newpath; }
};

struct sort_by_distance {
	bool operator() (const node &first, const node &second) {
		return first.get_total_distance() < second.get_total_distance();
	}
};
node get_shortest_path(graph& graph, int start, int end) {
	if (start == end) {
		cout << "start and end are the same. distance is 0" << endl;
		return node(start);
	}
	auto matrix = graph.get_adjacency_matrix();
	set<node, sort_by_distance> open;
	vector<node> closed;

	node startingNode = node(start);
	startingNode.add_to_path(start);

	open.insert(startingNode);

	while (!open.empty()) {
		node next = *open.begin();
		if (next.get_node_id() == end) {
			return next;
		}
		open.erase(open.begin());
		closed.push_back(next);
		
		auto row = matrix[next.get_node_id()];
		for (unsigned int i = 0; i < row.size(); i++) {
			int weight = row[i];
			if (weight == -1 || i == next.get_node_id()
				|| find_if(closed.begin(), closed.end(), [i](const node& n) {return i == n.get_node_id(); }) != closed.end()) {
				continue;
			}
			set<node>::const_iterator it = find_if(open.begin(), open.end(), [i](const node& n) {return i == n.get_node_id(); });
			vector<int> better_path = vector<int>(next.get_path());
			better_path.push_back(i);
			int new_distance = next.get_total_distance() + weight;
			if (it == open.end()) {
				open.insert(node(i, new_distance, better_path));
			}
			else {
				node found = *it;
				int old_distance = found.get_total_distance();
				if (new_distance < old_distance) {
					open.erase(it);
					open.insert(node(i, new_distance, better_path));
				}
			}
		}
	}
	return 0;
}

int main() {
	
	int num_of_nodes;
	double density;
	cout << "Enter number of nodes in a graph:" << endl;
	cin >> num_of_nodes;
	cout << "Enter density of the graph:" << endl;
	cin >> density;
	random_graph_generator graphGenerator;
	auto g = graphGenerator.generateGraph(num_of_nodes, density);
	cout << "Generated graph:" << endl << *
		g << endl;

	node n = get_shortest_path(*g, 0, num_of_nodes - 1);

	cout << "shortest distance: " << n.get_total_distance() << endl;
	cout << "path: ";
	for (unsigned int i = 0; i < n.get_path().size(); i++) {
		cout << n.get_path()[i] << " ";
	}
	cout << endl;
	return 0;
}
