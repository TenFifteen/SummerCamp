/*
题目大意：
给定一个数组，数组中只有0，1，2三种数字。然后排序。

解题思路：
本来想着是计数排序不是挺好的么。一看题目，竟然有提示说可以有更优的方法。
然后就是弄两个指针分别指向当前0的边界和2的边界，一遍遍历就可以解决了。

遇到的问题：
本来这个一遍遍历的想法是没想出来的，只想出了计数排序。看了网上的解法才知道的。
看来还是功底不够啊。

再次阅读：
在没有读代码之前，我第一个想到的方法竟然是做两次二元排序。
相当于是第一遍将0和1、2分开；第二遍将1、2分开。
然后看到自己的代码后惊呆了，我竟然写出了这样的代码。。。
看了一下DISCUSS，其实当时就是借鉴的别人的代码了。
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size();
        for(int i = 0; i < right; ++i){
            if(nums[i] == 0){
                swap(nums[i], nums[++left]);
            }else if(nums[i] == 2){
                swap(nums[i], nums[--right]);
                --i;
            }
        }
    }
};
/*
第二次做：
原来的思路的确是挺好的了。不过这次竟然一次通过了一个比较正宗的三元排序算法。
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;

        int left = 0, right = nums.size()-1, last = 0;
        while (left <= right) {
            while (left <= right && nums[left] != 2) {
                if (nums[left] == 0) {
                    swap(nums[last], nums[left]);
                    last++;
                }
                left++;
            }
            while (left <= right && nums[right] == 2) {
                right--;
            }
            if (left < right) {
                swap(nums[left], nums[right--]);
            }
        }
    }
};
/*
 * very good
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;

        int i = 0, j = 0, k = nums.size()-1;
        while (i <= k) {
            if (nums[i] == 0) {
                swap(nums[j++], nums[i++]);
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[k--]);
            }
        }
    }
};
