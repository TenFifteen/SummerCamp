/*
题目：17 % 最大数 中等

题目大意：
给定一个数组，问将其中所有的数字组成的最大的一个字符串是多少？

解题思路：
排序。

遇到的问题：
经常把排序函数写错，因为要实现的是小于。
而且还要考虑两个字符串比较之后的那些东西，比如2小于28，但是2大于21
*/
class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    struct Cmp {
        bool operator() (int lh, int rh) {
            string left = to_string(lh);
            string right = to_string(rh);
            int index_l = 0, index_r = 0;
            while (index_l != left.size() || index_r != right.size()) {
                if (index_l == left.size()) index_l = 0;
                if (index_r == right.size()) index_r = 0;
                if (left[index_l] < right[index_r]) return true;
                if (left[index_l] > right[index_r]) return false;
                index_l++;
                index_r++;
            }
            return false;
        }
    };

    string largestNumber(vector<int> &num) {
        // write your code here
        sort(num.begin(), num.end(), Cmp());
        if (num[num.size()-1] == 0) return string("0");
        string ans;
        for (int i = num.size()-1; i >= 0; --i) {
            ans += to_string(num[i]);
        }
        return ans;
    }
};
