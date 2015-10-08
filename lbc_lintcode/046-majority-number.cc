/*
题目：40 % 主元素 容易

题目大意：
给定一个数组，其中有一个数的数量超过了整个数组的一半，找到它

解题思路：
用二分的思路，如果存在这样的数，那么肯定在左半边或者右半边肯定会满足同样的条件。

遇到的问题：
竟然有一个地方把r写成了l，真是罪过啊。

精彩解答：
网上有人用位操作的方式解决；
有用计数的方式解决；
还有用求中位数数的思路解决：
http://blog.csdn.net/wutingyehe/article/details/46833267
http://www.cnblogs.com/pczhou/p/4684288.html

感觉自己还是做麻烦了。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        auto ret = sub(nums, 0, nums.size()-1);
        return ret.second;
    }
    
    pair<bool, int> sub(vector<int> &nums, int left, int right) {
        if (left > right) {
            return make_pair(false, 0);
        }
        if (left == right) {
            return make_pair(true, nums[left]);
        }
        int mid = left + (right-left+1)/2;
        auto ret_l = sub(nums, left, mid-1);
        auto ret_r = sub(nums, mid, right);
        if (ret_l.first == false && ret_r.first == false) {
            return make_pair(false, 0);
        } else if (ret_l.first == false) {
            if (count(nums, left, right, ret_r.second) > (right-left+1)/2) {
                return ret_r;
            } else {
                return make_pair(false, 0);
            }
        } else if (ret_r.first == false) {
            if (count(nums, left, right, ret_l.second) > (right-left+1)/2) {
                return ret_l;
            } else {
                return make_pair(false, 0);
            }
        } else {
            if (ret_l == ret_r) return ret_l;
            int cnt_l = count(nums, left, right, ret_l.second);
            int cnt_r = count(nums, left, right, ret_r.second);
            if (cnt_l > (right-left+1)/2) return ret_l;
            if (cnt_r > (right-left+1)/2) return ret_r;
            return make_pair(false, 0);
        }
    }
    
    int count(vector<int> &nums, int left, int right, int val) {
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            if (nums[i] == val) ret++;
        }
        return ret;
    }
};

