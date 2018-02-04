/**
 * Problem: Given two lists Aand B, and B is an anagram of A. B is an anagram of
 *          A means B is made by randomizing the order of the elements in A.
 *          We want to find an index mapping P, from A to B. A mapping P[i] = j means
 *          the ith element in A appears in B at index j.
 *          These lists A and B may contain duplicates. If there are multiple answers, output any of them.
 * Solve: map
 * Tips:no
 */
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>> countB;
        for (int i = 0; i < B.size(); ++i) {
            countB[B[i]].push_back(i);
        }

        vector<int> res(A.size());
        for (int i = 0; i < A.size(); ++i) {
            res[i] = countB[A[i]].back();
            countB[A[i]].pop_back();
        }

        return res;
    }
};
