/*
题目：28 % Cosine Similarity new 容易

题目大意：
给定两个向量，求其cos角度

解题思路：
根据公式直接算

遇到的问题：
没有问题。
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
        if (A.size() == 0 || A.size() != B.size()) return 2.0;
        double mulA = 0, mulB = 0, mulAB = 0;
        for (int i = 0; i < A.size(); ++i) {
            mulA += A[i]*A[i];
            mulB += B[i]*B[i];
            mulAB += A[i]*B[i];
        }
        if (mulA == 0 || mulB == 0) return 2.0; 
        return mulAB/sqrt(mulA)/sqrt(mulB);
    }
};

