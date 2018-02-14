/**
 * Problem: A string S of lowercase letters is given. We want to partition this
 *          string into as many parts as possible so that each letter appears in
 *          at most one part, and return a list of integers representing the
 *          size of these parts.
 * Solve: right border
 * Tips: no
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int right[256] = {0};
        for (int i = 0; i < 256; ++i) {
            right[i] = -1;
        }

        int n = S.size();
        for (int i = 0; i < n; ++i) {
            right[S[i]] = max(right[S[i]], i);
        }

        vector<int> res;
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            if (right[S[i]] == r && i == r) {
                //cout << "i=" << i << "; S[i]=" << S[i] << "; r=" << r << endl;
                res.push_back(r-l+1);
                l = r = i + 1;
            } else {
                r = max(r, right[S[i]]);
            }
        }

        return res;
    }
};
