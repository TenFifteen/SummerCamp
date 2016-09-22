class Solution {
public:
    bool canCross(vector<int>& stones) {
        find = false;
        if (stones.size() == 1) return true;
        if (stones.size() == 2 && stones[1] != 1) return false;

        dfs(stones, 1, 1);
        return find;
    }

    bool find = false;
    void dfs(vector<int> &stones, int pos, int step) {
        if (find) return;

        if (pos == stones.size()-1) {
            find = true;
            return;
        }

        for (int i = pos+1; i < stones.size(); ++i) {
            if (stones[i]-stones[pos] > step+1) break;
            if (stones[i]-stones[pos] < step-1) continue;

            dfs(stones, i, stones[i]-stones[pos]);
        }
    }
};
