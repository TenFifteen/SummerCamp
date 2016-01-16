/*
题目大意：
给一个数组，给一个target值。求出所有能加起来等于target的四个数的组合。

解题思路：
跟3sum的思路一样，只不过再加了一层。

遇到的问题：
还是边界值的问题，一般如果题目没有确定说一定有解，一定要注意边界问题。
另外就是left，right的更新也要细心一点。

再次阅读：
这个题差不多也就是n三次方的最优解了吧。
不过如果只是问是否存在，而不是找到所有的情况的话，倒是可以用hash的方式，
但是感觉hash的方式的情况处理比较复杂，需要各种判断重复条件等。
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4)return ans;
        sort(nums.begin(), nums.end());
        int last = 0;
        for(int i = 0; i < nums.size()-3; ++i){
            if(i != 0 && last == nums[i]){
                continue;
            }
            last = nums[i];
            int last1 = 0;
            for(int j = i+1; j < nums.size()-2; ++j){
                if(j != i+1 && last1 == nums[j]){
                    continue;
                }
                last1 = nums[j];
                int left = j+1;
                int right = nums.size()-1;
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        ans.push_back(tmp);
                        while(left < right && nums[left+1] == nums[left]){
                            left++;
                        }
                        left++;
                    }else if(sum < target){
                        while(left < right && nums[left+1] == nums[left]){
                            left++;
                        }
                        left++;
                    }else{
                        while(right > left && nums[right-1] == nums[right]){
                            right--;
                        }
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};