/*
题目大意：
给定一个无序数组，求出在其有序的情况下，相邻两个元素的最大差值是多少？

解题思路：
用同排序的思路。
将桶的数目设置成元素的个数。那么平均一个桶有一个元素。
如果有一个桶里有多个元素， 那么就有别的桶是空着的。那么也就是说，最大的gap不可能出现在同一个
桶里。所以只需要计算相邻有数据的桶的最大gap就行了。

遇到的问题：
自己没想出来，还是看的别人的思路。
参考：http://www.cnblogs.com/skysand/p/4179099.html

再次阅读：
这次倒是记得了桶排序了。
这种思路简直就是好极了。
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)return 0;
        int big = nums[0], small = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > big)big = nums[i];
            if(nums[i] < small)small = nums[i];
        }
        int bucket_size = (big-small+1)/nums.size();
        if((big-small+1)%nums.size() != 0)bucket_size++;
        vector<pair<int,int>> buckets(nums.size(), make_pair(INT_MAX,INT_MIN));
        for(int i = 0; i < nums.size(); ++i){
            int id = (nums[i]-small)/bucket_size;
            buckets[id].first = min(buckets[id].first, nums[i]);
            buckets[id].second = max(buckets[id].second, nums[i]);
        }
        int last = INT_MIN;
        int ret = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            if(buckets[i].second == INT_MIN)continue;
            if(last != INT_MIN){
                if(buckets[i].first-last > ret){
                    ret = buckets[i].first - last;
                }
                last = buckets[i].second;
            }else{
                last = buckets[i].second;
            }
        }
        return ret;
    }
};
/*
第二次做：
极好的思路。
这次代码也写得不错，一次成功。
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int minVal = INT_MAX, maxVal = -1;
        for (auto n : nums) {
            minVal = min(minVal, n);
            maxVal = max(maxVal, n);
        }
        int n = nums.size(), len = maxVal-minVal+1;
        int bucketSize = len/n;
        if (len % n) bucketSize++;
        
        typedef pair<int, int> bucket;
        vector<bucket> b(n, make_pair(INT_MAX, -1));
        
        for (auto num : nums) {
            int buckNum = (num-minVal)/bucketSize;
            b[buckNum].first = min(b[buckNum].first, num);
            b[buckNum].second = max(b[buckNum].second, num);
        }
        
        bool lastValid = false;
        bucket last;
        int ans = 0;
        for (auto buck : b) {
            if (buck.first > buck.second) continue;
            if (lastValid == false) {
                lastValid = true;
                last = buck;
            } else {
                ans = max(ans, buck.first - last.second);
                last = buck;
            }
        }
        return ans;
    }
};