/**
 * Problem: Given two words (start and end), and a dictionary, find the length of
 *          shortest transformation sequence from start to end, such that:
 *             Only one letter can be changed at a time
 *             Each intermediate word must exist in the dictionary
 * Solve: bfs, we can also use bi-bfs & hashset
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param start, a string
         * @param end, a string
         * @param dict, a set of string
         * @return an integer
         */
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            int ans = 0;

            queue<string> q1, q2, *now = &q1, *next = &q2;

            now->push(start);
            int len = start.size();
            int step = 1;

            while (!now->empty()) {
                ++step;

                while (!now->empty()) {
                    string cur = now->front();
                    now->pop();

                    for (int i = 0; i < len; ++i) {
                        char ch = cur[i];
                        for (char c = 'a'; c <= 'z'; ++c) {
                            cur[i] = c;
                            if (cur == end) return step;

                            if (dict.find(cur) != dict.end()) {
                                dict.erase(cur);
                                next->push(cur);
                            }
                        }
                        cur[i] = ch;
                    }
                }

                swap(now, next);
            }

            return 0;
        }
};
