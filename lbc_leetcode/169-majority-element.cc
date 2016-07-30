/*
题目大意：
给定一个数组，求其中的众数。也就是有一个元素的个数超过了n/2了。

解题思路：
二分

遇到的问题：
一次通过。

再次阅读：
原来这种分治的方法没啥问题，就是代码稍微麻烦一点。
如果采用计数的方案的话，代码会简洁很多，而且还不需要递归：
public class Solution {
    public int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;

        }
        return major;
    }
}
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        auto ret = sub(nums, 0, nums.size()-1);
        return ret.first;
    }

    pair<int, bool> sub(vector<int> &nums, int left, int right){
        if(left > right){
            return make_pair(0, false);
        }
        if(left == right){
            return make_pair(nums[left], true);
        }
        int mid = left + (right-left+1)/2;
        auto ret_l = sub(nums, left, mid-1);
        auto ret_r = sub(nums, mid, right);
        if(ret_l.second){
            int cnt = 0;
            for(int i = left; i <= right; ++i){
                if(nums[i] == ret_l.first)cnt++;
            }
            if(cnt > (right-left+1)/2)return ret_l;
        }
        if(ret_r.second){
            int cnt = 0;
            for(int i = left; i <= right; ++i){
                if(nums[i] == ret_r.first)cnt++;
            }
            if(cnt > (right-left+1)/2)return ret_r;
        }
        return make_pair(0, false);
    }
};
/*
第二次做：
经典老题，问题不大。注意细节。
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        assert(nums.size() > 0);

        int ans = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == ans) cnt++;
            else cnt--;
            if (cnt < 0) {
                ans = nums[i];
                cnt = 1;
            }
        }
        return ans;
    }
};
/*
 * so so
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt == 0) {
                cnt = 1;
                m = nums[i];
            }
            else if (nums[i] == m) cnt++;
            else cnt--;
        }
        return m;
    }
};
