/**
 * Problem: A linked list is given such that each node contains an additional random
 *          pointer which could point to any node in the list or null
 * Solve: dfs
 * Tips: see below
 */
RandomListNode *dfs(RandomListNode *node, unordered_map<int, RandomListNode *> &visited) {
	RandomListNode *now = new RandomListNode(node->label);
	visited[node->label] = now;

	if (node->next) {
		if (visited.find(node->next->label) == visited.end()) {
			RandomListNode *next = dfs(node->next, visited);
			now->next = next;
		} else {
			now->next = visited[node->next->label];
		}
	}

	if (node->random) {
		if (visited.find(node->random->label) == visited.end()) {
			RandomListNode *random = dfs(node->random, visited);
			now->random = random;
		} else {
			now->random = visited[node->random->label];
		}
	}

	// dont forget to return the now pointer
	return now;
}

RandomListNode *copyRandomList(RandomListNode *head) {
	if (NULL == head) return NULL;
	unordered_map<int, RandomListNode *> visited;
	return dfs(head, visited);
}

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<int, RandomListNode*> nodeMap;
        return dfs(nodeMap, head);
    }

    RandomListNode *dfs(unordered_map<int, RandomListNode*> &nodeMap, RandomListNode *now) {
        if (now == NULL) return NULL;
        if (nodeMap.find(now->label) != nodeMap.end()) return nodeMap[now->label];

        RandomListNode *clone = new RandomListNode(now->label);
        nodeMap[now->label] = clone;
        clone->next = dfs(nodeMap, now->next);
        clone->random = dfs(nodeMap, now->random);

        return clone;
    }
};
