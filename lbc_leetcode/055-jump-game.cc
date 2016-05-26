/*
题目大意：
给一个数组，每一个数字表示该点可以往后跳多远。求，从0开始，能否跳到最后一个点？

解题思路：
跟45题相似。其实应该是先做这个题，再做45题。反正思路都一样。

遇到的问题：
一次通过。

再次阅读：
之前的算法应该是没有什么问题了，O(n)的复杂度应该是最好的了。
只是代码可以更简洁一些：
bool canJump(int A[], int n) {
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
}
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0)return false;
        if(nums.size() == 1)return true;
        int cur = 0,len = 1,dist = nums[0];
        while(true){
            if(dist >= nums.size()-1)return true;
            if(dist < cur+len)return false;
            int tmp = 0;
            for(int i = cur+len; i <= dist; ++i){
                tmp = max(tmp, nums[i]+i);
            }
            cur = cur+len;
            len = dist-cur+1;
            dist = tmp;
        }
    }
};
/*
第二次做：
嗯，这次做的比较顺利，虽然没有上面DISCUSS中的代码写的简洁好看，不过也是还不错了。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        assert(nums.size());
        
        int cur = 0, maxJump = 0;
        while (maxJump+1 < nums.size()) {
            int newJump = maxJump;
            for (int i = cur; i <= maxJump; ++i) {
                newJump = max(newJump, nums[i] + i);
            }
            if (newJump == maxJump) return false;
            cur = maxJump+1;
            maxJump = newJump;
        }
        
        return true;
    }
};