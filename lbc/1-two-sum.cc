/*
题目大意：
有一个数组，给一个target值，从中找出两个数的下标，使得这两个数的和等于target。
题目保证，只有唯一的这样一对数可以满足条件。

解题思路：
将原来数组与下标共同组成一个新的数组，然后进行排序。排序之后，利用卡尺法进行查找。
排序的复杂度为nlog(n)，查找的复杂度是n。空间复杂度是n

遇到的问题：
一开始觉得既然结果是唯一的，那么两个数都是唯一的，没有其他的数据与之相同，然后用map
将原来的数和下标存储下来了，然后对原数组进行了排序。结果发现有可能这两个数本身是相等的，
所以得出了错误的结果。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nums_pair;
        for(int i = 0;i < nums.size(); ++i){
            nums_pair.push_back(make_pair(nums[i], i+1));
        }
        vector<int> ans;
        sort(nums_pair.begin(), nums_pair.end());
        int start = 0, end = nums.size()-1;
        while(start < end){
            int sum = nums_pair[start].first + nums_pair[end].first;
            if(sum == target){
                if(nums_pair[start].second > nums_pair[end].second){
                    ans.push_back(nums_pair[end].second);
                    ans.push_back(nums_pair[start].second);
                }else{
                    ans.push_back(nums_pair[start].second);
                    ans.push_back(nums_pair[end].second);
                }
                break;
            }
            else if(sum < target){
                start++;
            }else{
                end--;
            }
        }
        return ans;
    }
};
