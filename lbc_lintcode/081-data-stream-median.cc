/*
题目：23 % 中位数 II 困难

题目大意：
给定一个数据流，每进入一个数字，就要求前面所有数字的中位数。

解题思路：
用两个堆。一个堆保存前n/2的最小的数，一个保存前n/2的最大的数。

遇到的问题：
没想到

精彩解答：
http://www.cnblogs.com/easonliu/p/4441916.html
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> ans;
        multiset<int> left, right;
        bool flag = true;
        for (auto n : nums) {
            if (flag) {
                //insert into left min heap
                int tmp = n;
                if (right.size() != 0 && n > *right.begin()) {
                    tmp = *right.begin();
                    right.erase(right.find(tmp));
                    right.insert(n);
                }
                left.insert(tmp);
            } else {
                //insert into right max heap
                int tmp = n;
                if (left.size() != 0 && n < *left.rbegin()) {
                    tmp = *left.rbegin();
                    left.erase(left.find(tmp));
                    left.insert(n);
                }
                right.insert(tmp);
            }
            flag = !flag;
            ans.push_back(*left.rbegin());
        }
        return ans;
    }
};

