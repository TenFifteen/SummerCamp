/*
题目大意：
跟之前的抢劫是一样的，但是这次是首位也相连了。

解题思路：
分别计算去掉第一家和去掉最后一家的结果，取最大值。

遇到的问题：
被我想得稍微复杂了点。

再次阅读：
看了之前的思路，感觉跟DISCUSS中的思路差不多，但是代码明显写的没有人家好看。
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        if(nums.size() == 1)return nums[0];
        vector<int> rob(nums.size(), 0),norob(nums.size(), 0);
        rob[0] = nums[0];
        for(int i = 1; i < nums.size()-1; ++i){
            rob[i] = norob[i-1] + nums[i];
            norob[i] = max(norob[i-1], rob[i-1]);
        }
        int ret = max(rob[nums.size()-2], norob[nums.size()-2]);
        norob[1] = 0;
        rob[1] = nums[1];
        for(int i = 2; i < nums.size(); ++i){
            rob[i] = norob[i-1] + nums[i];
            norob[i] = max(norob[i-1], rob[i-1]);
        }
        return max(ret,max(rob[nums.size()-1], norob[nums.size()-1]));
    }
};
/*
第二次做：
做的比较顺利。遇到了一个小问题，就是这种情况下，需要单独处理只有一家人的时候。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int ans = nums[0], rob = nums[0], norob = 0;
        for (int i = 1; i < nums.size()-1; ++i) {
            int newrob = max(rob, norob+nums[i]);
            norob = max(rob, norob);
            rob = newrob;
            ans = max(ans, rob);
        }

        rob = nums[1], norob = 0;
        ans = max(ans, rob);
        for (int i = 2; i < nums.size(); ++i) {
            int newrob = max(rob, norob+nums[i]);
            norob = max(rob, norob);
            rob = newrob;
            ans = max(ans, rob);
        }

        return ans;
    }
};
/*
 * ok. but corner case not found.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) {
            if (nums.size() == 1) return nums[0]; // this is the corner case
            else return 0;
        }

        int ans = 0;
        int rob = 0, norob = 0;
        for (int i = 0; i+1 < nums.size(); ++i) {
            int new_rob = norob + nums[i];
            norob = max(norob, rob);
            rob = new_rob;
        }
        ans = max(rob, norob);

        rob = norob = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int new_rob = norob + nums[i];
            norob = max(norob, rob);
            rob = new_rob;
        }
        ans = max(ans, max(norob, rob));
        return ans;
    }
};
