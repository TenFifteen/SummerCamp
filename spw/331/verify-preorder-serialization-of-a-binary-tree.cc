/**
 * Problem: One way to serialize a binary tree is to use
 *          pre-order traversal. When we encounter a non-null
 *          node, we record the node's value. If it is a null
 *          node, we record using a sentinel value such as #.
 * Solve: 1. the last element must be #
 *        2. The count of # is twice of the count of nodes.
 *        3. In the sequence, the count of nodes must be more
 *        or equal than the count of nulls.
 * Tips: see comments below.
 */
#include <iostream>
#include <vector>

using namespace std;

bool isValidSerialization(string preorder) {
    int nodes = 0, nulls = 0;

    int len = preorder.size();
    if (len <= 0) return false;
    if (preorder[len-1] != '#') return false;

    --len;
    int s = 0, e = 0;
    while (e < len) {
        // use ++e to let e rest on ','
        while (e < len && preorder[++e] != ',');

        if (preorder.substr(s, e-s) == "#") nulls++;
        else nodes++;

        if (nulls > nodes) return false;

        s = ++e;

    }

    return nodes == nulls;

}
