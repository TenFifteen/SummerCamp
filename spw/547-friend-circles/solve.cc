/**
 * Problem: There are N students in a class. Some of them are friends,
 *          while some are not. Their friendship is transitive in nature.
 *          For example, if A is a direct friend of B, and B is a direct
 *          friend of C, then A is an indirect friend of C. And we defined
 *          a friend circle is a group of students who are direct or
 *          indirect friends.
 *          Given a N*N matrix M representing the friend relationship
 *          between students in the class. If M[i][j] = 1, then the ith and
 *          jth students are direct friends with each other, otherwise not.
 *          And you have to output the total number of friend circles among
 *          all the students.
 *
 * Solve: query and union set
 * Tips: see comments below.
 */
class Solution {
    public:
        int findCircleNum(vector<vector<int>>& M) {
            int n = M.size();
            if (n == 0) return 0;

            vector<int> father(n);
            initSet(father);

            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    if (M[i][j]) {
                        unionSet(father, i, j);
                    }
                }
            }

            // flatten all the relationship for compute set later.
            for (int i = 0; i < n; ++i) {
                father[i] = querySet(father, i);
            }

            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (father[i] != -1 && father[father[i]] != -1) {
                    cnt++;
                    father[father[i]] = -1;
                }
            }

            return cnt;
        }

        void initSet(vector<int> &father) {
            for (int i = 0; i < father.size(); ++i) {
                father[i] = i;
            }
        }

        int unionSet(vector<int> &father, int a, int b) {
            int aSet = querySet(father, a);
            int bSet = querySet(father, b);

            if (aSet != bSet) {
                father[aSet] = bSet;
            }

            return bSet;
        }

        int querySet(vector<int> &father, int a) {
            if (father[a] == a) {
                return a;
            }

            return father[a] = querySet(father, father[a]);
        }
};
