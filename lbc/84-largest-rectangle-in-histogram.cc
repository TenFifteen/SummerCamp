/*
题目大意：
给定一个数组，都是非负整数，求所有的柱条所能组成的最大的面积。（宽度为1）

解题思路：
对于任意一个整数，找出以该整数为最短板的矩形的最大的面积。也就是说，找出某一个区间，
该区间左边和右边的元素都是比该元素小的，但是区间内的元素都是比这个元素大的。
做法就是通过维护一个栈，栈里放的是递增的序列的下标，如果当前元素比栈顶元素大，就入栈；
否则就计算以栈顶元素为最短板的矩形的面积。因为只有在当前元素比栈顶元素小的时候才会弹出，
所以如果栈内只有一个元素，那么这个元素是前面遍历过的数据中最小的。

遇到的问题：
这个题目本来是不会的，看了网上人家的解答才理解的。
附上链接：http://blog.csdn.net/doc_sgl/article/details/11805519
这个题目最自然的想法应该是3次方的。
2次方的算法是：对于某个元素，计算对于以该元素为区间右边界的最大的面积，从右往左算，
可以省去n的寻找最小值的复杂度，所以是2次方的。
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.size() == 0)return 0;
        height.push_back(0);
        int index = 0;
        int ret = 0;
        stack<int> sta;
        while(index < height.size()){
            if(sta.empty() || height[sta.top()] <= height[index]){
                sta.push(index);
                index++;
            }else{
                int last = sta.top();
                sta.pop();
                int area = 0;
                if(sta.empty()){
                    area = index * height[last];
                }else{
                    area = (index - sta.top() - 1) * height[last];
                }
                if(area > ret){
                    ret = area;
                }
            }
        }
        return ret;
    }
};