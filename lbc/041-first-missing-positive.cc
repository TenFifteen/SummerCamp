/*
题目大意：
给一个数组，求出该数组中缺少的第一个正整数。时间复杂度为n

解题思路：
将所有数据遍历一遍，将每个数组放到属于该数字的地方去。最后从头到尾遍历一遍，就可以找到第一个
缺少的正整数了。

遇到的问题：
一开始没想到这个方法，看了别人的思路才知道的。

再次阅读：
这次这个题目竟然一下子就想出来了。果然还是题目做多了有点好处，这种类型的题目
应该都可以用类似的手段。
看了一下DISCUSS，其中的最好的解法也就是这样子了。
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            int index = nums[i]-1;
            while(index >= 0 && index < nums.size()){
                int tmp = nums[index]-1;
                nums[index] = index+1;
                if(tmp != index){
                    index = tmp;
                }else{
                    break;
                }
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
/*
第二次做：
这次竟然是自己想出来了，还不错。
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i+1) continue;
            if (nums[i] > nums.size() || nums[i] <= 0) continue;
            
            int cur = nums[i];
            nums[i] = 0;
            while (cur > 0 && cur <= nums.size()) {
                int next = nums[cur-1];
                nums[cur-1] = cur;
                if (cur == next) break; //prevent dead loop
                cur = next;
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};