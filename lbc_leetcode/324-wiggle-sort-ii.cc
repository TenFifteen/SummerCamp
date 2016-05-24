/*
题目大意：
给定一个数组，将其中的元素放置为num[0] < num[1] > num[2] < num[3] > num[4]...这种形式

解题思路：
就是先将数组进行排序，然后将排序之后的数组元素一个小的一个大的这样依次放回来。

遇到的问题：
一开始看到题目中有要求要用O(n)的时间复杂度，O(1)的空间复杂度。
所以一个思路都没有想出来，本来是想到了找到一个中位数，然后放一个小的放一个大的。
但是没有成功。
这个题目还有一个先前的题目，不是严格的大于小于，而是<=和>=，所以相对来讲就很简答了。
就是直接贪心法求解就行了。
不过这个题目还是有一个挑战的时间和空间限制。只能放到“再次阅读”里面说了。

再次阅读：
这道题目最好的解法是一种利用三路分区排序算法改造的，首先介绍一下三路排序算法
（https://en.wikipedia.org/wiki/Dutch_national_flag_problem#Pseudocode）
问题就是将小于val的元素放到最前面，等于val的元素放到中间，大于val的元素放到后面：
伪代码：
procedure three-way-partition(A : array of value, mid : value):
    i ← 0
    j ← 0
    n ← size of A - 1

    while j ≤ n:
        if A[j] < mid:
            swap A[i] and A[j]
            i ← i + 1
            j ← j + 1
        else if A[j] > mid:
            swap A[j] and A[n]
            n ← n - 1
        else:
            j ← j + 1

然后这道题的解法就是首先将一个数组的坐标映射为1、3、5、7...、0、2、4、6、8...这样子，
然后进行three-way partition 算法：
void wiggleSort(vector<int>& nums) {
    int n = nums.size();

    // Find a median.
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        
        int j = 0, k = (nums.size()+1)/2;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (i & 0x1) {
                nums[i] = tmp[k++];
            } else {
                nums[i] = tmp[j++];
            }
        }
    }
};
/*
第二次做：
这道题的确是挺难的了。
两个算法的结合，首先是用到了用O(n)的复杂度找中位数的技术，
然后是用到了三路分区算法。
最重要的思想是进行下标替换的过程。
*/
class Solution {
    int nthElement(vector<int> &nums, int left, int right, int k) {
        int L = left, R = right;
        int mid = nums[L];
        while (L < R) {
            while (L < R && nums[R] > mid) R--;
            nums[L] = nums[R];
            while (L < R && nums[L] <= mid) L++;
            nums[R] = nums[L];
        }
        nums[L] = mid;
        
        if (L == k) return nums[L];
        if (L < k) return nthElement(nums, L+1, right, k);
        else return nthElement(nums, left, L-1, k);
    }
    
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        
        int n = nums.size(), mid = (n-1)/2;
        mid = nthElement(nums, 0, n-1, mid);
        
        #define A(i) (((i*2)+1)%(n|1))
        
        int i = 0, j = 0, k = n-1;
        while (j <= k) {
            if (nums[A(j)] > mid) {
                swap(nums[A(j++)], nums[A(i++)]);
            } else if (nums[A(j)] < mid) {
                swap(nums[A(j)], nums[A(k--)]);
            } else {
                j++;
            }
        }
    }
};