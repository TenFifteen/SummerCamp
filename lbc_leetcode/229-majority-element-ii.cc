/*
题目大意：
给定一个数组，求出其中所有的数量超过n/3的数字。

解题思路：
二分查找。

遇到的问题：
一开始忘记了两遍结果的去重。
并且将只有两个元素的情况搞错了。

再次阅读：
感觉除了这种递归的方式，好像没有想出更好的办法来。
结果在DISCUSS中找到了一个类似于解决一个数超过一半的那个题目的解法的解法：
感觉还是非常巧妙和厉害的。
vector<int> majorityElement(vector<int>& nums) {
    int cnt1=0, cnt2=0;
    int a,b;

    for(int n: nums){
        if (cnt1 == 0 || n == a){
            cnt1++;
            a = n;
        }
        else if (cnt2 == 0 || n==b){
            cnt2++;
            b = n;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1=cnt2=0;
    for(int n: nums){
        if (n==a)   cnt1++;
        else if (n==b) cnt2++;
    }

    vector<int> result;
    if (cnt1 > nums.size()/3)   result.push_back(a);
    if (cnt2 > nums.size()/3)   result.push_back(b);
    return result;
}
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        return sub(nums, 0, nums.size()-1);
    }

    vector<int> sub(vector<int> &nums, int left, int right){
        vector<int> ans;
        if(right < left)return ans;
        if(left == right){
            ans.push_back(nums[left]);
            return ans;
        }
        if(left+1 == right){
            ans.push_back(nums[left]);
            if(nums[right] != nums[left])ans.push_back(nums[right]);
            return ans;
        }
        int mid = left + (right-left+1)/2;
        auto ret_l = sub(nums, left, mid);
        auto ret_r = sub(nums, mid+1, right);

        set<int> visited;

        for(auto r:ret_l){
            if(visited.count(r))continue;
            int cnt = 0;
            for(int i = left; i <= right; ++i){
                if(nums[i] == r)cnt++;
            }
            if(cnt > (right-left+1)/3){
                ans.push_back(r);
                visited.insert(r);
            }
        }
        for(auto r:ret_r){
            if(visited.count(r))continue;
            int cnt = 0;
            for(int i = left; i <= right; ++i){
                if(nums[i] == r)cnt++;
            }
            if(cnt > (right-left+1)/3){
                ans.push_back(r);
                visited.insert(r);
            }
        }
        return ans;
    }
};
/*
第二次做：
DISCUSS中的代码是有问题的。对于[1,2,2,3,2,1,1,3]这个测试用例就过不了。
所以我根据人家的思路，自己实现了一个安全的版本。
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long a = LONG_LONG_MAX, b = a;
        int cnt1 = 0, cnt2 = 0;

        for (auto n : nums) {
            if (a == n) {
                cnt1++;
            } else if (b == n) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnt1 = 1;
                a = n;
            } else if (cnt2 == 0) {
                cnt2 = 1;
                b = n;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (auto n : nums) {
            if (n == a) cnt1++;
            else if (n == b) cnt2++;
        }

        vector<int> ans;
        if (cnt1 > nums.size()/3) ans.push_back(a);
        if (cnt2 > nums.size()/3) ans.push_back(b);
        return ans;
    }
};
/*
 * very good question. prone to be wrong
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x1, x2, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (x1 == nums[i] && cnt1 > 0) {
                cnt1++;
            } else if (x2 == nums[i] && cnt2 > 0) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnt1 = 1;
                x1 = nums[i];
            } else if (cnt2 == 0) {
                cnt2 = 1;
                x2 = nums[i];
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x1) cnt1++;
            if (nums[i] == x2) cnt2++;
        }
        if (cnt1 > nums.size()/3) ans.push_back(x1);
        if (cnt2 > nums.size()/3 && (ans.size() == 0 || ans.back() != x2)) ans.push_back(x2);
        return ans;
    }
};
