/*
题目大意：
有一个字符串。求出这个字符串中所有子串中，没有重复字母的子串的长度的最长值。

解题思路：
采用卡尺法，对于卡尺内的数据，保证都是没有重复字母的一个子串；如果当前考察的字母的数量不是0，
那么就把卡尺的左边前移，else就移动卡尺的右端。
时间复杂度：n，空间复杂度：1

遇到的问题：
中间对于buffer的使用，经常容易忘记使用s的字符，而容易用front或者end来索引，导致问题。这个问题的出现，
一方面是由于疏忽，一方面是因为int和char之间可以互相转换。

再次阅读：
原来我以为自己用的卡尺已经是足够优化了，已经是n的复杂度了。但是看了DISCUSS之后发现，别人的代码
竟然可以做到一次遍历，而我的代码相当于是两次遍历。
他们用的方法就是记住某个字母最后出现的一个位置，维护一个start不断的往前走。如下：
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> charMap;
        int start = -1;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }

        return maxLen;
    }
};
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)return s.size();
        int front = 1;
        int end = 0;
        int ans = 1;
        map<char,int> buffer;
        buffer[s[0]]++;
        while(front < s.size()){
            if(buffer[s[front]] != 0){
                buffer[s[end]]--;
                end++;
            }else{
                buffer[s[front]]++;
                front++;
                if(front - end > ans){
                    ans = front - end;
                }
            }
        }
        return ans;
    }
};

/*
第二次做：
这次用的又是卡尺法，不过也算是挺好了。 但是DISCUSS那种不错的解法还是没有领悟好。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        
        unordered_map<char, int> hash;
        hash[s[0]] = 1;
        int last = 0, ans = 1;
        
        for (int i = 1; i < s.size(); ++i) {
            hash[s[i]]++;
            while (hash[s[i]] > 1) {
                hash[s[last++]]--;
            }
            
            ans = max(ans, i-last+1);
        }
        
        return ans;
    }
};