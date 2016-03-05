/*
题目大意：
给定两个字符串表示的版本号，比较其大小。

解题思路：
将其转化为整数数组，然后进行比较。

遇到的问题：
竟然1.0 == 1

再次阅读：
看到了上次的“遇到的问题”部分，感觉这次做还是会遇到的。
另外就是这其实真是一道简单题目。不过代码还可以有另外一种写法：
int compareVersion(string version1, string version2) {
    int i = 0; 
    int j = 0;
    int n1 = version1.size(); 
    int n2 = version2.size();

    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }

        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }

        if(num1>num2) return 1;
        else if(num1 < num2) return -1;

        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }

    return 0;
}
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
/*
第二次做：
虽然这次思路没有问题，代码本身也没有太大问题。
不过却发现了一个语言上的重要的问题，就是如果一个函数需要返回值，你没有返回，
估计是一个随机值吧。
*/
class Solution {
private:
    int getNext(string &s, int &index) {
        int ret = 0;
        while (index < s.size() && s[index] != '.') {
            ret *= 10;
            ret += s[index++] - '0';
        }
        
        index++;
        return ret;
    }

public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        int index1 = 0, index2 = 0;
        
        while (index1 < len1 || index2 < len2) {
            int num1 = getNext(version1, index1);
            int num2 = getNext(version2, index2);
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }
};