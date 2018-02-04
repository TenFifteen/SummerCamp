/**
 * Problem: On a 2x3 board, there are 5 tiles represented by the integers 1 through 5,
 *          and an empty square represented by 0.
 *          A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
 *          The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
 *          Given a puzzle board, return the least number of moves required
 *          so that the state of the board is solved. If it is impossible for
 *          the state of the board to be solved, return -1.
 * Solve: bfs,
 * Tips: when traverse, rightmost of first line, leftmost of second line are not adjacent
 */
class Solution {
    public:
        int slidingPuzzle(vector<vector<int>>& board) {
            unordered_set<int> visited;

            queue<pair<int, int>> positions;
            int p = getPosition(board), target = 0x123450;

            positions.push(make_pair(p, 0));
            while (!positions.empty()) {
                auto now = positions.front();
                positions.pop();

                if (now.first == target) return now.second;
                if (visited.find(now.first) != visited.end()) continue;
                visited.insert(now.first);

                vector<int> nexts = getMove(now.first);
                for (int next : nexts) {
                    if (visited.find(next) == visited.end()) {
                        positions.push(make_pair(next, now.second+1));
                    }
                }
            }

            return -1;
        }

        int getPosition(vector<vector<int>>& board) {
            int code = 0;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 3; ++j) {
                    code = (code << 4) | board[i][j];
                }
            }

            return code;
        }


        vector<int> getMove(int position) {
            vector<int> digits(6, 0);
            int zi = 0, prev = position;

            for (int i = 0; i < 6; ++i) {
                digits[i] = position & 0xf;
                if (digits[i] == 0) zi = i;

                position >>= 4;
            }

            vector<int> ans;
            const int diff[4] = {1, -1, 3, -3};
            for (int i = 0; i < 4; ++i) {
                int ni = zi + diff[i];
                if (ni < 0 || ni > 5) continue;
                if (zi == 2 && ni == 3 || zi == 3 && ni == 2) continue;

                int next = prev;
                next -= digits[ni] << (ni * 4);
                next += digits[ni] << (zi * 4);

                ans.push_back(next);
            }

            return ans;
        }
};
