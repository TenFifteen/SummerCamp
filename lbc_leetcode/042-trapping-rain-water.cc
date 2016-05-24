/*
题目大意：
给一个非负的数组，假设每个宽度是1.从上面下雨，问该数组最大的盛水量。

解题思路：
找出每一个数字的左右边界的最小值。如果该边界比自己大，就可以计算自己可以盛多少水。

遇到的问题：
无问题。

再次阅读：
再次看到这个题目的时候，竟然一下子就想出来了，而且是跟原来的解法一样的。
然后看了一下DISCUSS中的解法，其实人家比我的解法要好很多，少了一个n的空间。
就是用两个指针的方式往中间走，不断的更新左右最高纪录，这样的话，就可以省掉了空间复杂度了。
这样做的insight就是当前如果更新的是左边的值，说明maxleft要小于等于maxright，要不然就应该是
先访问maxright这个值了。所以可以只用maxleft来界定水的高度。
感觉实在是精妙啊。
class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)return 0;
        vector<int> water(height.size(), -1);
        int bar = height[0];
        for(int i = 1; i < height.size(); ++i){
            water[i] = max(bar, height[i]);
            bar = max(bar, height[i]);
        }
        bar = height[height.size()-1];
        for(int i = height.size()-2; i >= 0; --i){
            water[i] = min(water[i], bar);
            bar = max(bar, height[i]);
        }
        int ans = 0;
        for(int i = 1; i < height.size()-1; ++i){
            if(water[i]-height[i] > 0)ans += water[i]-height[i];
        }
        return ans;
    }
};
/*
第二次做：
跟第一次做差不多，还是没有用到DISCUSS中的O(1)空间复杂度的思路。
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        
        vector<int> left_max(height.size(), 0);
        left_max[0] = height[0];
        for (int i = 1; i < height.size(); ++i) {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        
        int ans = 0, right_max = height[height.size()-1];
        for (int i = height.size()-2; i > 0; --i) {
            int bar = min(left_max[i-1], right_max);
            if (bar > height[i]) {
                ans += bar - height[i];
            }
            right_max = max(right_max, height[i]);
        }
        
        return ans;
    }
};