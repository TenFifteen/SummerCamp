/*
题目大意：
给定一个数组，将其右移k位。

解题思路：
按照之前的翻转字符串中的单词的题目的思路，可以将前后两部分分别翻转，再将整个
数组翻转。

遇到的问题：
一开始没想到，只是看到了题目的提示才想到的。

再次阅读：
这道题目说想到越多越好的方法，然后看了一下DISCUSS中的解法，的确是足够多了：
1，用一个额外的空间记录当前数组，然后再将其按照右移后的位置拷贝回来
2，从一个元素开始，直接将其放到其应该放到的位置上，一直做，做完了n次就完了。
3，就是我这种，先翻转前半部分，然后是后半部分，然后是全部
4，先把后面k个元素与前面k个元素交换；这时候将数组缩短为[arr+k,arr+n)然后继续交换
5，
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        sub(nums, 0, nums.size()-k-1);
        sub(nums, nums.size()-k, nums.size()-1);
        sub(nums, 0, nums.size()-1);
    }
    
    void sub(vector<int> &nums, int left, int right){
        for(int i = left; i < left + (right-left+1)/2; ++i){
            swap(nums[i], nums[right+left-i]);
        }
    }
};
/*
第二次做：
虽然挺简单的，还是出了一个错误。就是sub中的条件，写成了i < left + (right-left)/2了。
太粗心了。一定要好好改改。
*/
class Solution {
private:
    void rotateSub(vector<int> &nums, int left, int right) {
        for (int i = left; i < left + (right-left+1)/2; ++i) {
            swap(nums[i], nums[right-i+left]);
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        
        k %= n;
        if (k == 0) return;
        
        rotateSub(nums, 0, n-1);
        rotateSub(nums, 0, k-1);
        rotateSub(nums, k, n-1);
    }
};