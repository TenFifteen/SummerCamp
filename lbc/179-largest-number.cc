/*
题目大意：
给定一个数组，问如果将其所有数字排列起来，哪一种排成的数字最大。

解题思路：
排序

遇到的问题：
忘记了处理输出的前导0

再次阅读：
算法是想起来了，感觉也没啥问题。不过在DISCUSS中有一个更简单的方法，实在是厉害极了：
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};
还有就是上面提到的，前导0的处理也不能忘了。
*/
class Solution {
private:
    struct Cmp{
        bool operator() (int a, int b){
            string as = to_string(a);
            string bs = to_string(b);
            int len = min(as.size(), bs.size());
            for(int i = 0; i < len; ++i){
                if(as[i] > bs[i])return false;
                if(as[i] < bs[i])return true;
            }
            if(as.size() > len){
                return operator()(stoi(as.substr(len, as.size()-len)), b);
            }
            if(bs.size() > len){
                return operator()(a, stoi(bs.substr(len, bs.size()-len)));
            }
            return false;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), Cmp());
        for(int i = nums.size()-1; i >= 0; --i){
            ans += to_string(nums[i]);
        }
        int index = 0;
        while(index < ans.size() && ans[index] == '0')index++;
        if(index == ans.size())ans = "0";
        else ans = ans.substr(index, ans.size()-index);
        return ans;
    }
};