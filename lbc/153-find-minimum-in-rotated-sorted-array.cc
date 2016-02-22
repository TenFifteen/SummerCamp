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