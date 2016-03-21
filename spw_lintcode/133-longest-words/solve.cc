/**
 * Problem: Given a dictionary, find all of the longest words in the dictionary.
 * Solve: one pass
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param dictionary: a vector of strings
         * @return: a vector of strings
         */
        vector<string> longestWords(vector<string> &dictionary) {
            // write your code here

            int maxLen = 0;
            vector<string> ans;
            int len = dictionary.size();

            for (int i = 0; i < len; ++i) {
                if (dictionary[i].size() > maxLen) {
                    while (!ans.empty()) ans.pop_back();
                    ans.push_back(dictionary[i]);
                    maxLen = dictionary[i].size();
                } else if(dictionary[i].size() == maxLen) {
                    ans.push_back(dictionary[i]);
                }
            }

            return ans;
        }
};
