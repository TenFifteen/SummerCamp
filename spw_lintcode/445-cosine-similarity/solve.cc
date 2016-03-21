/**
 * Problem: Cosine similarity is a measure of similarity between
 *          two vectors of an inner product space that measures
 *          the cosine of the angle between them. The cosine of 0° i
 *          s 1, and it is less than 1 for any other angle.
 * Solve: simulate
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A: An integer array.
         * @param B: An integer array.
         * @return: Cosine similarity.
         */
        double cosineSimilarity(vector<int> A, vector<int> B) {
            if (A.size() != B.size()) return 2.0000;

            int len = A.size();
            double dotProduct = 0;
            for (int i = 0; i < len; ++i) {
                dotProduct += A[i]*B[i];
            }

            long long lenA = 0, lenB = 0;
            for (int i = 0; i < len; ++i) {
                lenA += A[i]*A[i];
                lenB += B[i]*B[i];
            }

            if (lenA == 0 || lenB == 0) return 2.0000;

            return dotProduct/(sqrt(lenA) * sqrt(lenB));
        }
};

