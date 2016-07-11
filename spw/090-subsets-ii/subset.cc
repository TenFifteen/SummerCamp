#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> > &ans, int pos, int n, int len, vector<int> now, vector<int> &nums)
{
    if (now.size() == len) {
        ans.push_back(now);
        return;
    }

    // every time we select a number as now[j], j = 0...len-1
    // every time we have serveral choices: nums[i], i = pos...n-1
    // So we need notice that if we select number 'a' in now[j]
    // we should avoid selecting other 'a' int now[j]
    for (int i = pos; i < n; ++i) {
        now.push_back(nums[i]);
        dfs(ans, i+1, n, len, now, nums);
        now.pop_back();
        // skip other nums[i]
        while (i+1 < n && nums[i+1] == nums[i]) ++i;
    }
}

/**
 * Problem: Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 * Sovle: backtrace
 * Tips: trverse every posible lenght(notice 0)
 */
vector<vector<int> > subsetsWithDup(vector<int>& nums)
{
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());
    for (int len = 0; len <= nums.size(); len++) {
        vector<int> now;
        dfs(ans, 0, nums.size(), len, now, nums);
    }

    return ans;
}

int main()
{
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            nums[i] = temp;
        }
        vector<vector<int> > ans = subsetsWithDup(nums);

        cout << "-----------------" << endl;
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < ans[i].size(); ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans(1, vector<int>());

            sort(nums.begin(), nums.end());
            int k = 0;
            while (++k <= nums.size()) {
                vector<int> now;
                dfs(ans, nums, now, k, 0);
            }

            return ans;
        }

        void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> &now, int k, int pos) {
// if we lay if(pos >= nums.size()) return; here. we will miss some valid results.
            if (now.size() == k) {
                ans.push_back(now);
                return;
            }

            while (pos < nums.size()) {
                now.push_back(nums[pos]);
                dfs(ans, nums, now, k, pos+1);
                now.pop_back();

                while (++pos < nums.size() && nums[pos] == nums[pos-1]);
            }
        }
};

/**
 * only need to remember all the middle nodes and leaves.
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> now;
        dfs(ans, nums, now, 0);

        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> &now, int pos) {
        ans.push_back(now);

        while (pos < nums.size()) {
            now.push_back(nums[pos]);
            dfs(ans, nums, now, pos+1);
            now.pop_back();

            while (++pos < nums.size() && nums[pos] == nums[pos-1]);
        }
    }
};


/**
copy from benchao: 稍微修改了些，关于k的
其实我想了一下，感觉这个题目可以用这种思路来考虑。就是没有重复的子集合是可以直接
对每个元素都认为有两种可能，就是选和不选。
而有重复的数字的子集合就是可以理解成为选取该数字的个数的可能是从[0,k], k是该数字的个数。
在具体实现的时候，可以通过利用前面的集合来填入新元素扩充成新的集合。对于前面的集合，可以
认为该元素没有选，然后分别选[1, k]个元素，填入。
这样理解的话，感觉就好理解一些了。
而且，如果从这个角度来看的话，下面这种非递归的方式也是挺好的：
*/
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
                for(int j=1; j<=count; j++){
                    instance.push_back(S[i]);
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
        }
};
