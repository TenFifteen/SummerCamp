/**
 * Problem: Given an array and a value, remove all occurrences of that value in place and return the new length.
 *          The order of elements can be changed, and the elements after the new length don't matter.
 * Solve: move in place
 * Tips: no
 */
class Solution {
    public:
        /**
         **@param A: A list of integers
         **@param elem: An integer
         **@return: The new length after remove
         **/
        int removeElement(vector<int> &A, int elem) {
            int cnt = 0;
            int n = A.size();

            for (int i = 0; i < n; ++i)
                if (A[i] != elem)
                    A[cnt++] = A[i];

            return cnt;

        }

};
