/*
题目大意：
给一个数组，求出所有的排列。数字有重复。

解题思路：
用树的层次来防止重复。

遇到的问题：
本来46题就已经处理了重复了。
结果发现其实是有问题的，去掉了之前的处理方式，换成了：
while(i+1 < nums.size() && nums[i+1] == nums[i])i++;

再次阅读：
再次看这道题，依然会犯之前的错误。
看了之前的代码，竟然感觉没有什么道理。
看了一下DISCUSS中的解法，人家依然是那么简洁：
class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> flag(nums.size(), false);
        vector<int> cur;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        sub(ans, nums, cur, flag);
        return ans;
    }

    void sub(vector<vector<int>> &ans, vector<int> &nums, vector<int> &cur, vector<bool> &flag){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(flag[i])continue;
            //if(i != 0 && nums[i] == nums[i-1])continue;
            cur.push_back(nums[i]);
            flag[i] = true;
            sub(ans, nums, cur, flag);
            cur.pop_back();
            flag[i] = false;
            while(i+1 < nums.size() && nums[i+1] == nums[i])i++;
        }
    }
};
/*
第二次做：
这次也是采用的之前自己的思路，竟然还是犯了之前的老毛病，不过这次的处理方式跟之前不同了。
*/
class Solution {
private:
    void dfs(vector<vector<int> > &ans, vector<int> &nums, vector<int> &cur, vector<bool> &flag) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        bool valid = false;
        int last;
        for (int i = 0; i < nums.size(); ++i) {
            if (flag[i] || (valid && nums[i] == last)) continue;

            cur.push_back(nums[i]);
            flag[i] = true;
            dfs(ans, nums, cur, flag);
            cur.pop_back();
            flag[i] = false;

            valid = true;
            last = nums[i];
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<bool> flag(nums.size(), false);
        vector<int> cur;
        sort(nums.begin(), nums.end());

        dfs(ans, nums, cur, flag);
        return ans;
    }
};
/*
 * 这次还是没有自己完美的写出来。最后还是参考了一些上面的记录。
 * 他竟然是用的非引用的nums，也是够厉害的。引用在这里是很有问题的。
 */
class Solution {
private:
    void generate(vector<vector<int>> &ans, vector<int> nums, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[index]) continue;
            swap(nums[index], nums[i]);
            generate(ans, nums, index+1);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        generate(ans, nums, 0);
        return ans;
    }
};
