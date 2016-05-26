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
/*
第二次做：
这次做的不好。
虽然一开始代码写的跟之前一样，但是竟然对于1，1，1这样的用例是错误的。
不知道为啥，看起来跟之前是一样的啊。
还是DISCUSS这种方式比较好。也不需要迭代。
另外就是最后还有一个前导0的处理也很重要。还有就是处理前导0的时候，不要忘记了最后要剩一个0.
*/
class Solution {
private:
    struct Cmp {
        bool operator() (int lh, int rh) {
            string left = to_string(lh), right = to_string(rh);
            int index = 0;
            
            return left+right < right+left;
            
            while (index < left.size() && index < right.size()) {
                if (left[index] < right[index]) return true;
                if (left[index] > right[index]) return false;
                index++;
            }
            
            if (index == left.size()) return operator()(lh, stoi(right.substr(index)));
            if (index == right.size()) return operator()(stoi(left.substr(index)), rh);
            return false;
        }
    };

public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) return "";
        
        sort(nums.begin(), nums.end(), Cmp());
        
        string ans;
        for (int i = nums.size()-1; i >= 0; --i) {
            ans += to_string(nums[i]);
        }
        
        int index = 0;
        while (index < ans.size() && ans[index] == '0') index++;
        if (index == ans.size()) return "0";
        return ans.substr(index);
    }
};