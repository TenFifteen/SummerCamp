/**
 * Problem: You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots:
 * '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap
 * around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
 *
 * The lock initially starts at '0000', a string representing the state of the 4 wheels.
 *
 * You are given a list of deadends dead ends, meaning if the lock displays any of
 * these codes, the wheels of the lock will stop turning and you will be unable to open it.
 *
 * Given a target representing the value of the wheels that will unlock the lock, return
 * the minimum total number of turns required to open the lock, or -1 if it is impossible.
 *
 * Solve: bfs
 * Tips: see comments
 */
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads;
        for (auto d : deadends) {
            deads.insert(d);
        }

        // first check1
        if (deads.find("0000") != deads.end()) return -1;

        queue<string> paths;
        unordered_set<string> visited;

        paths.push("0000");
        visited.insert("0000");

        int res = 0;
        while (!paths.empty()) {
            int n = paths.size();
            while(n--) {
                auto now = paths.front();
                paths.pop();
                if (now == target) return res;

                for (int i = 0; i < 4; ++i) {
                    char c = now[i];

                    if (c == '0') now[i] = '9';
                    else now[i] = c - 1;
                    if (visited.find(now) == visited.end() &&
                        deads.find(now) == deads.end()) {
                        paths.push(now);
                        visited.insert(now);
                    }

                    if (c == '9') now[i] = '0';
                    else now[i] = c + 1;
                    if (visited.find(now) == visited.end() &&
                       deads.find(now) == deads.end()) {
                        paths.push(now);
                        visited.insert(now);
                    }

                    now[i] = c;
                }
            }

            res++;
        }


        return -1;
    }
};
