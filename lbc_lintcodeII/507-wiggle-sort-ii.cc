/*
题目大意：
将数组排序成0<1>2<3>4..这种形式。

解题思路：
见代码。

遇到的问题：
没有问题了。
不过这道题其实好难啊。
*/
class Solution {
    int findMiddle(vector<int> &nums) {
        int L = 0, R = nums.size()-1, k = nums.size()/2;
        
        while (L < R) {
            int left = L, right = R, mid = nums[L];
            while (left < right) {
                while (left < right && nums[right] > mid) right--;
                nums[left] = nums[right];
                while (left < right && nums[left] <= mid) left++;
                nums[right] = nums[left];
            }
            nums[left] = mid;
            
            if (left == k) return mid;
            else if (left > k) R = left-1;
            else L = left+1;
        }
        
        return nums[L];
    }
    
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        if (nums.size() < 2) return;
        
        int mid = findMiddle(nums);
        int n = nums.size();
        
        #define A(i) (nums[((i)*2+1)%(n|1)])
        
        int i = 0, j = 0, k = n-1;
        while (i <= k) {
            if (A(i) > mid) {
                swap(A(j++), A(i++));
            } else if (A(i) == mid) {
                i++;
            } else {
                swap(A(i), A(k--));
            }
        }
    }
};