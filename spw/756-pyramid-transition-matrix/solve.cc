/**
 * Problem: We are stacking blocks to form a pyramid. Each block has a color which
 *          is a one letter string, like `'Z'`.
 *          For every block of color `C` we place not in the bottom row,
 *          we are placing it on top of a left block of color `A` and right
 *          block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.
 *
 *          We start with a bottom row of bottom, represented as a single string.
 *          We also start with a list of allowed triples allowed. Each allowed
 *          triple is represented as a string of length 3.
 *
 *          Return true if we can build the pyramid all the way to the top, otherwise false.
 * Solve: dfs
 * Tips: see comments
 */
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<int, vector<int>> rules;

        for (auto& al : allowed) {
            int key = getKey(al, 0);
            int val = al[2] - 'A';

            if (rules.find(key) == rules.end()) {
                rules[key] = vector<int>(1, val);
            } else {
                rules[key].push_back(val);
            }
        }

        bool res = false;
        dfs(rules, bottom, 0, res);

        return res;
    }

    void dfs(unordered_map<int, vector<int> >& rules, string level, int pos, bool& res) {
        if (res) return;

        if (pos == level.size()-1) {
            level.pop_back();
            pos = 0;
        }

        // the judgement must comes after the previous, because after pop may left only one element
        if (level.size() == 1) {
            res = true;
            return;
        }

        //cout << level << endl;

        int key = getKey(level, pos);
        if (rules.find(key) == rules.end()) return;


        for (auto& val : rules[key]) {
            string next = level;
            next[pos] = 'A' + val;

            dfs(rules, next, pos+1, res);
        }
    }

    int getKey(const string &rule, int pos) {
        return ((rule[pos]-'A') << 3) | (rule[pos+1] - 'A');
    }


};
