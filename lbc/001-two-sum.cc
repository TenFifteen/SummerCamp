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

再次阅读：
最笨的方法就是选定一个数，搜索剩下的所有数，n*n的复杂度。但是优点就是空间复杂度为O(1).
然后就是想到的排序后卡尺。
但是看到遇到的问题的地方的时候，感觉自己当时是不是有点笨啊。
完全可以直接从前往后遍历，找target-nums[i]是否在hash表中啊。
看了一下DISCUSS，的确最好的解法就是这样的：
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
            result.push_back(hash[numberToFind] + 1);
            result.push_back(i + 1);            
            return result;
        }

            //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}
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

/*
第二次做：
这次做的比较不错了。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            if (um.find(target-nums[i]) != um.end()) {
                vector<int> ans(2);
                ans[0] = um[target-nums[i]]+1;
                ans[1] = i+1;
                return ans;
            }
            if (um.find(nums[i]) == um.end()) {
                um[nums[i]] = i;
            }
        }
    }
};