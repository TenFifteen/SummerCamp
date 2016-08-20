/*
题目大意：
给定一组单词。定义两个单词的乘积为其长度的乘积。
然后要求所有没有交集的单词的乘积的最大值。

解题思路：
由于输入中只有小写字母，所以可以确定最多有26个字母。然后可以将其映射到
整数的bit上。这样就可以用整数操作来表示两个字符串是否是相交的。

遇到的问题：
一开始没有想到这种映射方式。只是直接拿字符串进行hash看是否是相交的了。

再次阅读：
看了一下之前代码，感觉自己的这种word到int的映射还是挺巧妙的。
但是看了一下之前的解题思路，才知道原来原来也不是自己想出来的啊。
看了下DISCUSS之后才发现，其实大家基本都是这么用的。
以后要记住这种26字母可以映射到int这种方式。
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n < 3) return 0;
        vector<int> bit(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                bit[i] |= (1 << (words[i][j]-'a'));
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((bit[i] & bit[j]) == 0) {
                    int cur = words[i].size() * words[j].size();
                    ans = max(ans, cur);
                }
            }
        }

        return ans;
    }
};
/*
第二次做：
做的不错。
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() < 2) return 0;

        int n = words.size();
        vector<int> mask(n, 0);

        for (int i = 0; i < n; ++i) {
            for (auto ch : words[i]) {
                mask[i] |= (1 << (ch-'a'));
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (!(mask[i] & mask[j])) {
                    int mul = words[i].size() * words[j].size();
                    ans = max(ans, mul);
                }
            }
        }

        return ans;
    }
};
/*
 * ok
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> arr(words.size());
        for (int i = 0; i < words.size(); ++i) {
            for (auto ch : words[i]) {
                arr[i] |= 1 << (ch-'a');
            }
        }

        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                if (arr[i] & arr[j]) continue;
                int mul = words[i].size() * words[j].size();
                ans = max(ans, mul);
            }
        }
        return ans;
    }
};


