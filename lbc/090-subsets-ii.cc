/*
题目大意：
给定一个数字的集合，数字有重复。找出所有的组合的可能。

解题思路：
用深搜（回溯）的思想。对于递归树的某一层来讲，不可以使用同一个数字两次，也就
达到了去重的目的。

遇到的问题：
这道题目原来我好像是用的set来去重的。感觉不太好，就上网找了一下，找到了这个思路。
不过我还是不能用递归树的思路来想这个问题。还要多思考一下这个问题。
参考：http://www.cnblogs.com/x1957/p/3517989.html

再次阅读：
其实我想了一下，感觉这个题目可以用这种思路来考虑。就是没有重复的子集合是可以直接
对每个元素都认为有两种可能，就是选和不选。
而有重复的数字的子集合就是可以理解成为选取该数字的个数的可能是从[0,k-1]k是该数字的个数。
这样理解的话，感觉就好理解一些了。
而且，如果从这个角度来看的话，下面这种非递归的方式也是挺好的：
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > totalset = {{}};
        sort(S.begin(),S.end());
        for(int i=0; i<S.size();){
            int count = 0; // num of elements are the same
            while(count + i<S.size() && S[count+i]==S[i])  count++;
            int previousN = totalset.size();
            for(int k=0; k<previousN; k++){
                vector<int> instance = totalset[k];
                for(int j=0; j<count; j++){
                    instance.push_back(S[i]);
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
        }
};


*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0)return ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        sub(ans, cur, nums, 0);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &cur, vector<int> &nums, int index){
        ans.push_back(cur);
        for(int i = index; i < nums.size(); ++i){
            if(i != index && nums[i] == nums[i-1])continue;
            cur.push_back(nums[i]);
            sub(ans, cur, nums, i+1);
            cur.pop_back();
        }
    }
};