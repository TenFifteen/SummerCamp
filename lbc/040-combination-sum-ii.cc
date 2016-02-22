/*
题目大意：
给一个数组，一个target。找出所有的子集合的和为target。不重复。

解题思路：
与39题类似。只是不许重复。在39题的代码上改两个地方就可以。
一个是如果当前处理的数字与上一个数字相同，就跳过。
另个一个就是递归的时候深度加一。

遇到的问题：
一开始忘了处理同一层对某个数字只处理一次的要求。

再次阅读：
看完了上一题的时候已经想明白了这种情况应该怎么处理了。
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> choose;
        sort(candidates.begin(), candidates.end());
        sub(ans, candidates, choose, target, 0, 0);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &choose, int target, int sum, int cur){
        if(sum == target){
            ans.push_back(choose);
            return;
        }
        if(sum > target)return;
        
        for(int i = cur; i < candidates.size(); ++i){
            if(i != cur && candidates[i] == candidates[i-1])continue;
            sum += candidates[i];
            choose.push_back(candidates[i]);
            sub(ans, candidates, choose, target, sum, i+1);
            sum -= candidates[i];
            choose.pop_back();
        }
    }
};
/*
第二次做：
一次通过，感觉这种题已经知道该怎么做了。
*/
class Solution {
private:
    void dfs(vector<vector<int> > &ans, vector<int> &candidates, int target, int sum, int index, vector<int> &cur) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        if (sum > target || index >= candidates.size()) return;
        
        cur.push_back(candidates[index]);
        dfs(ans, candidates, target, sum+candidates[index], index+1, cur);
        cur.pop_back();
        
        while (index+1 < candidates.size() && candidates[index] == candidates[index+1]) index++;
        dfs(ans, candidates, target, sum, index+1, cur);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        if (candidates.size() == 0) return ans;
        
        sort(candidates.begin(), candidates.end());
        
        vector<int> cur;
        dfs(ans, candidates, target, 0, 0, cur);
        return ans;
    }
};