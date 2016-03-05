/*
题目大意：
给定一个数组。从起点开始，在某个点最大可以跳该点的数字那么远，问跳到最后一个点
所需的最小的步数是多少

解题思路：
计算每一步所能达到的最远的范围，然后用该范围内的所有点计算下一步所能达到的最远的范围。

遇到的问题：
一开始看到就觉得是动态规划。结果竟然超时，加了一点优化还是不行。
才知道这道题用的是贪心算法。。

再次阅读：
终于再看到题目之后第一个想到的是贪心往前跳了。
看了一下DISCUSS中的方案，基本最优就是这样子了。
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        int step = 1;
        int cur = 0, len = 1;
        int dist = nums[0];
        while(dist < nums.size()-1){
            step++;
            cur = cur+len;
            len = dist+1-cur;
            dist = -1;
            for(int i = cur; i < cur+len; ++i){
                dist = max(dist, i+nums[i]);
            }
        }
        return step;
    }
    
    int jump2(vector<int>& nums) {
        vector<int> steps(nums.size(), INT_MAX);
        steps[0] = 0;
        for(int i = 0; i < nums.size()-1; ++i){
            if(steps[i]+1 >= steps[nums.size()-1])continue;
            for(int j = i+1; j <= i+nums[i] && j < nums.size(); ++j){
                steps[j] = min(steps[i]+1, steps[j]);
            }
        }
        return steps[nums.size()-1];
    }
};
/*
第二次做：
这次还比较顺利。一次就通过了。
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        assert(nums.size() > 0);
        if (nums.size() == 1) return 0;
        
        int start = 0, len = 0, steps = 0;
        while (len < nums.size()-1) {
            int nextLen = 0;
            for (int i = start; i <= len; ++i) {
                nextLen = max(nextLen, nums[i]+i);
            }
            steps++;
            start = len+1;
            len = nextLen;
        }
        
        return steps;
    }
};