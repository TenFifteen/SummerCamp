/*
题目大意：
给一个整数数组，一个target值。从中找出三个数相加的和与target最接近的那个和。

解题思路：
与15题是类似的。将数组先进性排序，然后固定第一个数，后两个数用卡尺进行寻找。

遇到的问题：
注意题目中说的是输出最接近的那个和，而不是与之的差值。

再次阅读：
与上一道题基本是一样的，只不过这次找的是最接近的那个解。
n*n应该是最优解了。
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i){
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int cur = nums[left] + nums[right] + nums[i];
                if(abs(cur-target) < ans){
                    ans = abs(cur-target);
                    ret = cur;
                }
                if(cur < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return ret;
    }

    int abs(int x){
        if(x < 0)return -x;
        return x;
    }
};
/*
第二次做：
这次做的真是顺利，果然是休息一下就好了。
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        assert(nums.size() > 2);

        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size()-2; ++i) {
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                int cur = nums[i] + nums[left] + nums[right];
                if (cur == target) return cur;
                if (abs(cur-target) < abs(ans-target)) {
                    ans = cur;
                }
                if (cur < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return ans;
    }
};
/*
 * 还可以
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int first = 0;
        int ans, minDiff = INT_MAX;
        while (first+2 < nums.size()) {
            int left = first+1, right = nums.size()-1;
            while (left < right) {
                int sum = nums[first] + nums[left] + nums[right];
                if (abs(sum-target) < minDiff) {
                    ans = sum;
                    minDiff = abs(sum - target);
                }
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }

            first++;
            while (first+2 < nums.size() && nums[first] == nums[first-1]) first++;
        }
        return ans;
    }
};
