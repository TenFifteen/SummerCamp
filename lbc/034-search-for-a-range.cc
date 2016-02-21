/*
题目大意：
给一个排序的数组，其中数字有可能有重复。给定一个target，找出target的左右边界；如果没有
就是-1，-1

解题思路：
分两次分别寻找左右边界。

遇到的问题：
竟然又一次做对了。所以呢，难题并不需要畏惧，想到了各种条件，应该就没问题。

再次阅读：
这个题目一看就不是很难，就是一个二分。只是需要在写代码的时候足够的细心，处理好各种情况。
其实我的代码应该是没有什么问题了，除了有点啰嗦之外。在DISCUSS中找到了另一份代码，感觉
还是挺好的，写的比较简洁：
vector<int> searchRange(int A[], int n, int target) {
    int i = 0, j = n - 1;
    vector<int> ret(2, -1);
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;

    // Search for the right one
    j = n-1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;   // Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;               // So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
}
尤其是在第二次搜索的时候，left从i开始，而不是从0开始，感觉这一点虽然效率上来讲可能提高了也就是一两次搜索的过程，
但是思想非常的棒。
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left = 0, right = nums.size()-1;
        int ans_left = nums.size();
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                if(mid < ans_left){
                    ans_left = mid;
                }
                right = mid;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
            if(left == right && nums[left] == target){
                ans_left = left;
                break;
            }
        }
        left = 0, right = nums.size()-1;
        int ans_right = -1;
        while(left <= right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] == target){
                if(mid > ans_right){
                    ans_right = mid;
                }
                left = mid;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
            if(left == right && nums[left] == target){
                ans_right = left;
                break;
            }
        }
        if(ans_right != -1){
            ans.push_back(ans_left);
            ans.push_back(ans_right);
        }else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
/*
第二次做：
代码有点啰嗦，不过直接做对了。
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.size() == 0) return ans;
        
        int L = INT_MAX, R = INT_MIN;
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                L = min(mid, L);
                right = mid-1;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        if (L == INT_MAX) return ans;
        
        left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                R = max(R, mid);
                left = mid+1;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        ans[0] = L;
        ans[1] = R;
        return ans;
    }
};