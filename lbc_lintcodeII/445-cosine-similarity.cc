/*
题目大意：
给定两个向量，求其cos值。

解题思路：
定义

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        if (A.size() != B.size()) return 2.0;
        
        double a = 0, b = 0, c = 0;
        for (int i = 0; i < A.size(); ++i) {
            a += A[i]*B[i];
            b += A[i]*A[i];
            c += B[i]*B[i];
        }
        
        if (b == 0 || c == 0) return 2.0;
        
        return a/sqrt(b)/sqrt(c);
    }
};
