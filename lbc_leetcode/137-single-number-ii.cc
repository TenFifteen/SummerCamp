/*
题目大意：
给定一个数组，其中只有一个数出现了一次，其他的都出现了3次。问这个出现了一次的数是多少？

解题思路：
用位来模拟。每个数出现了三次的话，其每个位都恰好是出现了三次。那么就可以每位变成了三进制。

遇到的问题：
竟然一次通过了。

再次阅读：
也是经典老题，但是感觉之前的代码很是啰嗦啊。显然是为了实现而实现的。
下面这种才是正宗的解法。
public int singleNumber(int[] A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.length; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}
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
/*
第二次做：
虽然知道怎么做，但是实在是想不出来DISCUSS中那种简洁的方式是怎么写的了。
最后还是参考的人家的代码。
这道题太经典了，一定要记住答案了。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int two = 0, one = 0;
        for (auto n : nums) {
            one = (one ^ n) & ~two;
            two = (two ^ n) & ~one;
        }
        return one;
    }
};
/*
 * old question. but this time finally resolve it
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (auto n : nums) {
            int tmp = n - (n & (one | two));
            two -= two & n;
            two += one & n;
            one -= one & n;
            one += tmp;
        }
        return one;
    }
};
