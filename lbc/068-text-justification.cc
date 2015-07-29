/*
题目大意：
给一堆字符串，按照一定的格式将其格式化。

解题思路：
用贪心的方法，一行一行的处理就行。

遇到的问题：
1，一开始有个边界问题搞了好久才发现。if(len > maxWidth)
2，没看清题目条件中最后一行的特殊情况。
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int left = 0, right = 0;
        while(left < words.size()){
            int len = words[left].size();
            right = left+1;
            while(len <= maxWidth && right < words.size()){
                len += 1+words[right].size();
                right++;
            }
            if(len > maxWidth){
                right--;
                len -= words[right].size()+1;
            }
            len -= right-left-1;
            
            string line = words[left];
            if(right-left == 1){
                string padding(maxWidth-len, ' ');
                line += padding;
            }else{
                if(right == words.size()){
                    for(int i = left+1; i < right; ++i){
                        line += " " + words[i];
                    }
                    string padding = string(maxWidth-len-(right-left-1), ' ');
                    line += padding;
                }
                else for(int i = left+1; i < right; ++i){
                    int whitespace = (maxWidth-len)/(right-left-1);
                    if(i-left <= (maxWidth-len)%(right-left-1)){
                        whitespace++;
                    }
                    string padding(whitespace, ' ');
                    line += padding;
                    line += words[i];
                }
            }
            ans.push_back(line);
            
            left = right;
        }
        return ans;
    }
};