/*
题目大意：
给一个数组，一个val。删除所有值为val的元素，返回长度。也是原地删除。

解题思路：
与26题一样。两个指针。

遇到的问题：
并没有问题。

再次阅读：
看了之前写的代码，感觉还是可以写的更简洁一些。
swap其实是没有必要的。
DISCUSS中有一个比较不错的简洁的例子：
int removeElement(int A[], int n, int elem) {
    int begin=0;
    for(int i=0;i<n;i++) if(A[i]!=elem) A[begin++]=A[i];
    return begin;
}
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)return 0;
        int len = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != val){
                if(i != len){
                    swap(nums[len], nums[i]);
                }
                len++;
            }
        }
        return len;
    }
};