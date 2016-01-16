/*
题目大意：
给一个数组，给出这个数组的排列的下一个排列。

解题思路：
根据排列的定义，从后往前找到第一组两个相邻的数，左边的小于右边的。
然后如果没找到，则当前的排列是最大的，也就是倒序的，直接翻转就行。
把当前扫描过的数字中第一个大于cur的数字，与cur交换。然后剩下的cur+1到
最后，直接翻转就行了。

遇到的问题：
需要注意数字中有相等的情况，也就是要注意大于号号大于等于号的使用。

再次阅读：
看了一下题目，竟然上来就想错了，竟然想着把找到的cur跟后面最大的数进行交换了。
实在是不应该啊。看了一下DISCUSS的代码，最好的情况也就是这种解法了。基本就是按照定义来的。
但是代码可以写的更好看一点，有些功能可以封装的更好一些，例如reverse，下面是一个用java写的
代码，不过人家的代码封装就要好很多，值得借鉴：
public void nextPermutation(int[] num) {
    int n=num.length;
    if(n<2)
        return;
    int index=n-1;        
    while(index>0){
        if(num[index-1]<num[index])
            break;
        index--;
    }
    if(index==0){
        reverseSort(num,0,n-1);
        return;
    }
    else{
        int val=num[index-1];
        int j=n-1;
        while(j>=index){
            if(num[j]>val)
                break;
            j--;
        }
        swap(num,j,index-1);
        reverseSort(num,index,n-1);
        return;
    }
}

public void swap(int[] num, int i, int j){
    int temp=0;
    temp=num[i];
    num[i]=num[j];
    num[j]=temp;
}

public void reverseSort(int[] num, int start, int end){   
    if(start>end)
        return;
    for(int i=start;i<=(end+start)/2;i++)
        swap(num,i,start+end-i);
}
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)return;
        int cur = nums.size()-2;
        while(cur >= 0 && nums[cur] >= nums[cur+1]){
            cur--;
        }
        if(cur < 0){
            for(int i = 0; i < nums.size()/2; ++i){
                swap(nums[i], nums[nums.size()-1-i]);
            }
            return;
        }
        int tmp = cur+1;
        while(tmp < nums.size() && nums[tmp] > nums[cur])tmp++;
        swap(nums[cur], nums[tmp-1]);
        for(int i = cur+1; i < cur+1+(nums.size()-cur)/2; ++i){
            swap(nums[i], nums[nums.size()-i+cur]);
        }
    }
};