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
/*
第二次做：
这次做的已经很熟练了，直接成功了。
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-3; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;

            for (int j = i+1; j < nums.size()-2; ++j) {
                if (j != i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1, right = nums.size()-1;
                while (left < right) {
                    int cur = nums[i] + nums[j] + nums[left] + nums[right];
                    if (cur == target) {
                        vector<int> tmp(4);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[left];
                        tmp[3] = nums[right];
                        ans.push_back(tmp);

                        while (left+1 < right && nums[left+1] == nums[left]) left++;
                        left++;
                    } else if (cur < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
/*
 * 还可以，一开始忘记了每次初始化second了
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;

        sort(nums.begin(), nums.end());
        int first = 0, second = 1;
        vector<int> tmp(4);

        while (first + 3 < nums.size()) {
            tmp[0] = nums[first];
            second = first + 1;

            while (second + 2 < nums.size()) {
                tmp[1] = nums[second];
                int left = second + 1, right = nums.size() - 1;

                while (left < right) {
                    int sum = nums[first] + nums[second] + nums[left] + nums[right];
                    if (sum == target) {
                        tmp[2] = nums[left];
                        tmp[3] = nums[right];
                        ans.push_back(tmp);
                        left++;
                        while (left < right && nums[left] == nums[left-1]) left++;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }

                second++;
                while (second + 2 < nums.size() && nums[second] == nums[second-1]) second++;
            }

            first++;
            while (first + 3 < nums.size() && nums[first] == nums[first-1]) first++;
        }

        return ans;
    }
};
