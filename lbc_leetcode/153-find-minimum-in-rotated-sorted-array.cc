/*
题目大意：
给定一个数组，本来是排序的。现在是旋转了一段。相当是：45670123

解题思路：
二分查找。

遇到的问题：
还是各种边界问题，莫非今天不适合刷题？

再次阅读：
还是二分，但是需要考虑清楚各种情况。
不过下面这段代码还是挺好的。
DISCUSS里还有一种稍微简洁一点的写法，可以借鉴一下：
int findMin(vector<int> &num) {
    int start=0,end=num.size()-1;

    while (start<end) {
        if (num[start]<num[end])
            return num[start];

        int mid = (start+end)/2;

        if (num[mid]>=num[start]) {
            start = mid+1;
        } else {
            end = mid;
        }
    }

    return num[start];
}
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(nums[right] > nums[left]){
                return nums[left];
            }else{
                if(nums[mid] > nums[left]){
                    left = mid+1;
                }else if(nums[mid] > nums[mid-1]){
                    right = mid-1;
                }else{
                    return nums[mid];
                }
            }
        }
        return nums[left];
    }
};
/*
第二次做：
比较顺利吧。
其实呢，二分写的时候主要的注意点就是mid的计算，已经left或者right到底哪个多算一个。
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return -1;

        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left+right)>>1;
            if (nums[left] < nums[right]) return nums[left];
            if (nums[mid] > nums[right]) left = mid+1;
            else right = mid;
        }

        return nums[left];
    }
};
/*
 * easy
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return INT_MIN;

        int left = 0, right = nums.size()-1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left];
            int mid = (left+right)/2;
            if (nums[mid] > nums[right]) left = mid+1;
            else right = mid;
        }
        return nums[left];
    }
};
