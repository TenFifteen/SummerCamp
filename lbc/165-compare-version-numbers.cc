/*
题目大意：
给定两个字符串表示的版本号，比较其大小。

解题思路：
将其转化为整数数组，然后进行比较。

遇到的问题：
竟然1.0 == 1
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1);
        auto v2 = split(version2);
        int index = 0;
        while(index < v1.size() && index < v2.size()){
            if(v1[index] > v2[index])return 1;
            if(v1[index] < v2[index])return -1;
            index++;
        }
        if(index < v1.size()){
            while(index < v1.size()){
                if(v1[index++] != 0)return 1;
            }
        }
        if(index < v2.size()){
            while(index < v2.size()){
                if(v2[index++] != 0)return -1;
            }
        }
        return 0;
    }
    
    vector<int> split(string s){
        vector<int> ret;
        int index = 0;
        int end = index;
        while(index < s.size()){
            while(end < s.size() && s[end] != '.')end++;
            ret.push_back(stoi(s.substr(index, end-index)));
            index = end+1;
            end = index;
        }
        return ret;
    }
};