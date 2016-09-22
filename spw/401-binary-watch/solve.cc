class Solution {

    int cntDigit(int n) {
        int cnt = 0;
        while (n) {
            ++cnt;
            n = n & (n - 1);
        }

        return cnt;
    }

public:
    vector<vector<int>> table;
    Solution() {
        table.resize(12, vector<int>(60));
        for (int i = 0; i <= 11; ++i) {
            int h = cntDigit(i);
            for (int j = 0; j <= 59; ++j) {
                int m = cntDigit(j);
                table[i][j] = h + m;
            }
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;

        for (int i = 0; i <= 11; ++i) {
            for (int j = 0; j <= 59; ++j) {
                if (table[i][j] == num) {
                    string h = to_string(i), m = to_string(j);
                    if (j < 10) m = '0' + m;
                    ans.push_back(h +":" + m);
                }
            }
        }

        return ans;
    }
};
