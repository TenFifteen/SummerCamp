/*
题目：15 % 滑动窗口的中位数 困难

题目大意：
给定一个数组。问每个滑动窗口的中位数是多少？

解题思路：
用两个堆来维护

遇到的问题：
没有问题。
不过这题写起来麻烦，所以要细心。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        if (nums.size() == 0 || nums.size() < k) {
            vector<int> tmp;
            return tmp;
        }
        for (int i = 0; i < k-1; ++i) {
            add(nums[i]);
        }
        vector<int> ans(nums.size()+1-k);
        for (int i = k-1; i < nums.size(); ++i) {
            add(nums[i]);
            ans[i-k+1] = get();
            rm(nums[i-k+1]);
        }
        return ans;
    }
    
private:
    multiset<int> left, right;//left small, right big
    void add(int x) {
        if (left.size() > right.size()) {//put to right
            if (x < *left.rbegin()) {
                left.insert(x);
                int tmp = *left.rbegin();
                left.erase(left.find(tmp));
                right.insert(tmp);
            } else {
                right.insert(x);
            }
        } else {//put to left
            if (right.size() == 0 || x <= *right.begin()) {
                left.insert(x);
            } else {
                right.insert(x);
                int tmp = *right.begin();
                right.erase(right.find(tmp));
                left.insert(tmp);
            }
        }
    }
    int get() {
        return *left.rbegin();
    }
    void rm(int x) {
        if (left.size() > right.size()) {
            if (left.find(x) != left.end()) {
                left.erase(left.find(x));
            } else {
                right.erase(right.find(x));
                int tmp = *left.rbegin();
                right.insert(tmp);
                left.erase(left.find(tmp));
            }
        } else {
            if (right.find(x) != right.end()) {
                right.erase(right.find(x));
            } else {
                left.erase(left.find(x));
                int tmp = *right.begin();
                right.erase(right.find(tmp));
                left.insert(tmp);
            }
        }
    }
};

