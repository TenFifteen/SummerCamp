/*
题目大意：
给定一个数组，寻找第k大的数

解题思路：
用快排思想

遇到的问题：
我一直以为快排要是实现为递归的才方便呢，而且上来写了一个竟然是有问题的。
然后看网上别人写的，http://www.cnblogs.com/easonliu/p/4523941.html
感觉不仅是非递归写的非常漂亮，而且写的也非常标准。

感觉快排一定要好好的练练，这种题目考场应该是送分题，一定要好好把握。

再次阅读：
这道题就是用这种快排思想来解决是最好的了。而且竟然还可以用迭代的方式实现。。

*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        int L = 0, R = nums.size()-1;
        while(L < R){
            int left = L, right = R;

            int mid = nums[left];
            while(left < right){
                while(left < right && nums[right] > mid)right--;
                nums[left] = nums[right];
                while(left < right && nums[left] <= mid)left++;
                nums[right] = nums[left];
            }
            nums[left] = mid;

            if(nums.size()-left-1 == k-1)return nums[left];
            else if(nums.size()-left-1 > k-1)L = left+1;
            else R = left-1;
        }
        return nums[nums.size()-k];
    }
};
/*
第二次做：
虽然这次用的是递归的快排，不过也是差不多的。
写的还算是可以。
*/
class Solution {
private:
    int quickFind(vector<int> &nums, int left, int right, int k) {
        if (left == right && k == 1) return nums[left];

        int mid = nums[left];
        int L = left, R = right;
        while (L < R) {
            while (L < R && nums[R] < mid) R--;
            nums[L] = nums[R];
            while (L < R && nums[L] >= mid) L++;
            nums[R] = nums[L];
        }
        nums[L] = mid;

        if (L-left == k-1) return nums[L];
        else if (L-left < k-1) return quickFind(nums, L+1, right, k-L+left-1);
        else return quickFind(nums, left, L-1, k);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickFind(nums, 0, nums.size()-1, k);
    }
};
/*
 * ok
 */
class Solution {
private:
    int quickFind(vector<int> &nums, int k, int left, int right) {
        cout << left << " " << right << endl;
        if (left > right) return -1;
        if (left == right) return nums[left];
        int mid = nums[left];
        int L = left, R = right;
        while (L < R) {
            while (L < R && nums[R] < mid) R--;
            nums[L] = nums[R];
            while (L < R && nums[L] >= mid) L++;
            nums[R] = nums[L];
        }
        nums[L] = mid;
        if (L == k-1) return mid;
        if (L > k-1) return quickFind(nums, k, left, L-1);
        else return quickFind(nums, k, L+1, right);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickFind(nums, k, 0, nums.size()-1);
    }
};
