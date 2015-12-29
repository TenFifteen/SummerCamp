/*
题目大意：
给定一个数组，n+1个元素，都是从1-n之间的数字。
可以证明，其中至少有一个数字是重复的。
假设只有一个重复的数字，找到该数字。

解题思路：
可以将每个数字放到其应该存在的位置。然后如果要放的位置如果已经有了
对应的数字的话，说明该数字重复。
不需要额外的空间复杂度，时间复杂度为O（1）

这个题目一开始搞错了。忘记了题目条件中要求的不可以更改原数组，复杂度小于n*n，不能使用额外空间。
然后看了一下DISCUSS。感觉想法真是碉堡了。其实这不就是那个有环的链表的问题么。
然后又按照链表的找第一个环节点的算法，写了一下这个题，然后竟然一次就对了。
说明思路非常重要啊。让我自己想，感觉是想不出来了。

遇到的问题：
一开始想不到任何思路，不过今天突然就想到了这个方法，感觉还是挺好的。
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[slow];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }
        
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }

    int findDuplicate2(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i+1) continue;
            while (nums[i] != i+1) {
                int next = nums[i]-1;
                if (nums[next] == nums[i]) return nums[i];
                swap(nums[i], nums[next]);
            }
        }
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i+1) continue;
            while (nums[i] != i+1) {
                int next = nums[i]-1;
                if (nums[next] == nums[i]) return nums[i];
                swap(nums[i], nums[next]);
            }
        }
    }
};