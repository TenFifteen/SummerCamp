/**
 * 问题: 罗马数字转整数。
 * 解决：做一个罗马单个数字和阿拉伯数字的对应表。然后遍历罗马字符串，将所有字面值相加，
 *       因为罗马字符串也是从左到右书写的，所以整体字面值应该是减小的，如果遇到增大的，
 *       那么必然说明前一个字符和该字符组成一个类似 IV XL CD的值，那么只需要将前一个
 *       罗马数字的字面值减去两次就行。
 * 注意：只是对应字面值的累加，并不需要乘以权重。
 */

class Solution {
    public:
        int romanToInt(string s) {
            static unordered_map<char, int> table;
            if (table.empty()) {
                table['I'] = 1;
                table['V'] = 5;
                table['X'] = 10;
                table['L'] = 50;
                table['C'] = 100;
                table['D'] = 500;
                table['M'] = 1000;
            }

            int n = s.size(), ans = 0, prev = 0;
            for (int i = 0; i < n; ++i) {
                int now = table[s[i]];
                ans += now;
                if (now > prev) ans -= 2 * prev;
                prev = now;
            }

            return ans;
        }
};
