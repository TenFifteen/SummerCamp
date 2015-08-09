#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;
/**
 ** Definition for undirected graph.
 **/
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* dfs(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &labels) {
	UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
	labels[node->label] = clone;

	vector<UndirectedGraphNode *> &neighbors = node->neighbors;
	for (int i = 0; i < neighbors.size(); ++i) {
		if (labels.find(neighbors[i]->label) == labels.end()) {
			UndirectedGraphNode* now_node = dfs(neighbors[i], labels);
			clone->neighbors.push_back(now_node);
		} else {
			clone->neighbors.push_back(labels[neighbors[i]->label]);
		}
	}

	return clone;
}

/**
 * Problem: Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * Solve: dfs and an visited vector
 * Tips: after clone should return the node 
 */
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (node == NULL) return NULL;
	unordered_map<int, UndirectedGraphNode *> labels;
	return dfs(node, labels);
}

int main()
{
	UndirectedGraphNode *root = new UndirectedGraphNode(-1);
	cloneGraph(root);

	return 0;
}
