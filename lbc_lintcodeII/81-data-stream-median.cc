/*
题目大意：
动态计算数组的中位数。

解题思路：
用两个堆，一个放小的一半；一个放大的一半。

遇到的问题：
没有问题。
*/
class Solution {
    priority_queue<int> left, right;
    
    void insert(int val) {
        left.push(val);
        right.push(-left.top());
        left.pop();
        
        if (right.size() > left.size()) {
            left.push(-right.top());
            right.pop();
        }
    }
    
    int getMiddle() {
        return left.top();
    }
    
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> ans(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            insert(nums[i]);
            ans[i] = getMiddle();
        }
        return ans;
    }
};
