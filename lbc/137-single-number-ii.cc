/*
题目大意：
给定一个数组，其中只有一个数出现了一次，其他的都出现了3次。问这个出现了一次的数是多少？

解题思路：
用位来模拟。每个数出现了三次的话，其每个位都恰好是出现了三次。那么就可以每位变成了三进制。

遇到的问题：
竟然一次通过了。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two = 0, three = -1;
        for(int i = 0; i < nums.size(); ++i){
            int tmp = nums[i];
            int add = one & tmp;
            tmp -= add;
            one -= add;
            two += add;
            
            add = tmp & two;
            tmp -= add;
            two -= add;
            three += add;
            
            add = tmp & three;
            three -= add;
            one += add;
        }
        return one;
    }
};