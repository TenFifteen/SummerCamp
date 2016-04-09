/**
 * Problem: Given an array of strings, return all groups of strings that are anagrams.
 * Solve: use a bool vector aside
 * Tips: no
 */
class Solution {
    public:
        /**
         ** @param strs: A list of strings
         ** @return: A list of strings
         **/
        vector<string> anagrams(vector<string> &strs) {
            vector<string> ans;
            int n = strs.size();
            if (n == 0) return ans;

            unordered_map<string, int> table;
            vector<int> flag(n ,false);
            for (int i = 0; i < n; ++i) {
                string key = strs[i];
                sort(key.begin(), key.end());

                if (table.find(key) == table.end()) {
                    table[key] = i;
                } else {
                    flag[i] = true;
                    flag[table[key]] = true;

                }

            }

            for (int i = 0; i < n; ++i)
                if (flag[i])
                    ans.push_back(strs[i]);


            return ans;

        }

};

