/*
题目大意：
把阿利伯数字转换成罗马数字。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        unordered_map<int, char> hash;
        hash[1] = 'I';
        hash[10] = 'X';
        hash[100] = 'C';
        hash[1000] = 'M';
        hash[5] = 'V';
        hash[50] = 'L';
        hash[500] = 'D';
        
        string ans;
        for (int base = 1000; base > 0; base /= 10) {
            int digit = n / base;
            n %= base;
            
            if (digit == 0) continue;
            else if (digit < 4) ans.append(digit, hash[base]);
            else if (digit == 4) {
                ans += hash[base];
                ans += hash[base*5];
            } else if (digit < 9) {
                ans += hash[base*5];
                ans.append(digit-5, hash[base]);
            } else {
                ans += hash[base];
                ans += hash[base*10];
            }
        }
        
        return ans;
    }
};
