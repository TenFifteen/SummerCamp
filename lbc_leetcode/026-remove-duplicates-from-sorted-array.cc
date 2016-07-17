/*
题目大意：
给一个数组，排好序了。然后要去重，并且是原地去重，最后返回去重后的长度。

解题思路：
两个指针，第一个指向当前要处理的数字，第二个指向当前所有有效的数字的位置。

遇到的问题：
一开始没看清题意，只是返回了长度。然后看了提示，知道使用两个指针来做的，才想起来。

再次阅读：
看完了题目之后，感觉差不多就是要排序之后进行遍历。然后再一看代码，才知道其实已经是排序过得了。
感觉其实没有必要swap。
然后看了一下DISCUSS，人家的写法更简单：
class Solution {
    public:
    int removeDuplicates(int A[], int n) {
        if(n < 2) return n;
        int id = 1;
        for(int i = 1; i < n; ++i)
            if(A[i] != A[i-1]) A[id++] = A[i];
        return id;
    }
};
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int last = nums[0];
        int len = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == last)continue;
            last = nums[i];
            swap(nums[i],nums[len]);
            len++;
        }
        return len;
    }
};
/*
第二次做：
是个简单题，一次通过了。
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]) {
                nums[len++] = nums[i];
            }
        }

        return len;
    }
};
/*
 * 尚可
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[len-1]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};
