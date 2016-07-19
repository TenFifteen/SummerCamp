/*
题目大意：
给定一个排序的数组，保证其中的数字都是唯一的。然后给定一个target，插入到数组中。
求插入的位置。

解题思路：
用二分法，当只有一个或者两个元素的时候，直接给出结果。

遇到的问题：
竟然又直接做对了，不过还是要注意边界，尤其是> 和>= 这两种不同的情况。

再次阅读：
虽然之前做的很顺利，但是感觉代码总是很冗余，比较啰嗦，所以就看了一下DISCUSS中的写的
比较简洁的方案，如下：
省去了很多情况的检查，其实那些检查都是没有必要的。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }

        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
        return low;
    }
};
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)return 0;
        int left = 0, right = nums.size()-1;
        while(left <= right){
            if(left == right){
                if(nums[left] >= target){
                    return left;
                }else{
                    return left+1;
                }
            }
            if(left+1 == right){
                if(nums[left] >= target)return left;
                if(nums[right] >= target)return right;
                return right+1;
            }

            int mid = left + (right-left)/2;
            if(nums[mid] == target)return mid;
            if(nums[mid] > target){
                right = mid;
            }else{
                left = mid;
            }
        }
    }
};
/*
第二次做：
感觉这次做的既顺利，代码又漂亮。
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;

        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }

        return right;
    }
};
/*
 * 还可以吧
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }

        if (nums[left] >= target) return left;
        else return left+1;
    }
};
