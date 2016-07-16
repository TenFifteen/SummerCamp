/*
题目大意：
给定一个字符串，给定一个行数。将字符串转化为倒着的Z的形状，然后按照Z的一行一行的顺序输出最后的字符串。

解题思路：
直接模拟。按照写Z的过程，将每个字符串分到每一行中去。
时间复杂度：n。空间复杂度：n

遇到的问题：
这个题目比较简单。

再次阅读：
感觉这的确是一个模拟题。很简单。看到DISCUSS里面也大都是这么做的。
但是我现在感觉好像是可以有另外一种更省空间的做法，就是直接按照数学规律，将每一行的字母逐个挑出来放到ans中。
虽然渐进意义上的时间和空间复杂度都是一样的，但是这样可以省掉很多的字符串拷贝拼接的时间。
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2)return s;
        vector<string> buf(numRows);
        int direction = 1;
        int i = 0;
        int index = 0;
        while(i < s.size()){
            buf[index].push_back(s[i]);
            i++;
            if(direction == 1){
                index++;
                if(index >= numRows){
                    direction = 0;
                    index = numRows-2;
                }
            }
            else{
                index--;
                if(index < 0){
                    direction = 1;
                    index = 1;
                }
            }
        }
        string ans;
        for(auto s: buf){
            ans += s;
        }
        return ans;
    }
};
/*
第二次做：
看了一下，感觉既然是个简单题，就暂时不做优化了，直接进行了模拟。
不过这次代码比之前短了一些，还是有点欣慰的。
*/
class Solution {
public:
    string convert(string s, int numRows) {
        assert(numRows > 0);
        if (numRows == 1) return s;

        vector<string> tmp(numRows);
        for (int i = 0; i < s.size(); ++i) {
            int cur = i % (numRows*2-2);
            if (cur >= numRows) {
                cur = 2*numRows-2-cur;
            }

            tmp[cur].push_back(s[i]);
        }

        string ans;
        for (auto str : tmp) {
            ans.append(str);
        }
        return ans;
    }
}
/*
 *又忘记了处理特殊情况。
 */
;class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; // special case.
        vector<string> vs(numRows);
        int index = 0;
        while (index < s.size()) {
            for (int i = 0; i < numRows-1 && index < s.size(); ++i) {
                vs[i].push_back(s[index++]);
            }
            for (int i = numRows-1; i > 0 && index < s.size(); --i) {
                vs[i].push_back(s[index++]);
            }
        }
        string ans;
        for (int i = 0; i < numRows; ++i) {
            ans += vs[i];
        }
        return ans;
    }
};
