/**
 * Problem: Given two words (start and end), and a dictionary, find all shortest
 *          transformation sequence(s) from start to end, such that:
 *          Only one letter can be changed at a time
 *          Each intermediate word must exist in the dictionary
 * Solve: bfs
 * Tips: delete after this level end instead of this word. See comments below.
 */
class Solution {
    public:
        /**
         * @param start, a string
         * @param end, a string
         * @param dict, a set of string
         * @return a list of lists of string
         */
        vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
            queue<string> q1, q2, *q1ptr = &q1, *q2ptr = &q2;
            int len = start.size();
            q1ptr->push(start);

            unordered_map<string, unordered_set<string> > parent;


            bool find = false;
            while (!q1ptr->empty() && !find) {

                unordered_set<string> used;
                while (!q1ptr->empty()) {
                    string cur = q1ptr->front();
                    q1ptr->pop();

                    string before = cur;
                    for (int i = 0; i < len; ++i) {
                        char tmp = cur[i];
                        for (char c = 'a'; c <= 'z'; ++c) {
                            cur[i] = c;
                            if (cur == end) {
                                parent[end].insert(before);
                                find = true;
                            }

                            if (dict.find(cur) != dict.end()) {
                                parent[cur].insert(before);
                                q2ptr->push(cur);
                                used.insert(cur);
                            }
                        }

                        cur[i] = tmp;
                    }
                }
                // delete the words this level meet, that is, we should not
                // use the before word in the behind rounds.
                for (string s : used) {
                    dict.erase(s);
                }

                swap(q1ptr, q2ptr);
            }

            vector<vector<string>> ans;
            vector<string> path;
            path.push_back(end);
            dfs(ans, parent, path, start);

            return ans;
        }


        void dfs(vector<vector<string>> &ans, unordered_map<string, unordered_set<string>> &parent, vector<string> path, string &start) {

            string now = path.back();
            if (now == start) {
                reverse(path.begin(), path.end());
                ans.push_back(path);
                return;
            }

            for (string p : parent[now]) {
                path.push_back(p);
                dfs(ans, parent, path, start);
                path.pop_back();
            }
        }
};
