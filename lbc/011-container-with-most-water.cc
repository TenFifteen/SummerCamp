/*
题目大意：
有一个非负数的数组。每个数字代表高度，然后计算任意两个点之间可以存放的水的数量的最大值。
比如i和j点，i<j，容量就是min(height[i], height[j]) * (j-i)

解题思路：
首先证明一点，如果当前的点为left，right的话；那么将height[left]和height[right]中小的那个
进行收缩，则有可能会使得容量增加，要不然就肯定是减小。
也就是说，如果一开始就从整个数组的两端开始，每次都是走可以提高水量的一种方式。那么最终最大的容量
肯定是可以算出来的。
时间复杂度：n；空间复杂度：1

遇到的问题：
这个题目乍看起来应该是用二维遍历可以解，但是复杂度太高。
然后我感觉的确应该是类似于两个指针来回指的，但是始终没想出来。
看完了答案，虽然感觉是对的，但是竟然无法证明。

回头看看他们的思路。

再次阅读：
这次一下子就想到了两个指针的方法了，看来还是之前做题有印象了。
看了DISCUSS后，其实最优解也是这么做的。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            int cur = min(height[left], height[right]) * (right-left);
            if(cur > ans){
                ans = cur;
            }
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};
/*
第二次做：
这次还是一下子就知道解法了，感觉这个题目的确是已经会做了啊。
而且，竟然代码写的也是如此的相似。。。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return false;
        
        int ret = 0, left = 0, right = height.size()-1;
        while (left < right) {
            int cur = min(height[left], height[right]) * (right-left);
            ret = max(ret, cur);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return ret;
    }
};