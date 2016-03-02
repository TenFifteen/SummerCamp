/*
题目大意：
给定一个数组，表示每个小朋友的rating值。现在给每个小朋友分糖。需要满足两个条件：
每个小朋友至少为1；具有高rating值的小朋友要比其邻居的糖果多。

解题思路：
贪心，从前往后一遍。从后往前一遍。

遇到的问题：
这个好像之前做过。
可以把小朋友想象成一个波浪线。从左往右可以满足单增的区间；从右往左可以满足单减的区间。

再次阅读：
是的，DISCUSS中最优的解法就是这样子的。
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0)return 0;
        vector<int> ans(ratings.size());
        ans[0] = 1;
        for(int i = 1; i < ratings.size(); ++i){
            if(ratings[i] > ratings[i-1]){
                ans[i] = ans[i-1]+1;
            }else{
                ans[i] = 1;
            }
        }
        for(int i = ratings.size()-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                if(ans[i] <= ans[i+1]){
                    ans[i] = ans[i+1]+1;
                }
            }
        }
        int ret = 0;
        for(int i = 0; i <ans.size(); ++i)ret += ans[i];
        return ret;
    }
};
/*
第二次做：
这次想明白为什么这样子做是对的了。
试想一下，如果ratings[k] > ratings[k-1]， 那么在反过来遍历的时候，
ratings[k]只会增长，不会降低；而ratings[k-1]肯定是不会变的。所以
两边的条件都满足了。
不过在写的时候，还是忘记了一个条件： && ans[i] <= ans[i+1]
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0) return 0;
        
        int n = ratings.size();
        vector<int> ans(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                ans[i] = ans[i-1]+1;
            }
        }
        
        for (int i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1] && ans[i] <= ans[i+1]) {
                ans[i] = ans[i+1] + 1;
            }
        }
        
        int sum = 0;
        for (auto a : ans) sum += a;
        return sum;
    }
};