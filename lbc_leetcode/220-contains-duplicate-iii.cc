/*
题目大意：
给定一个数组，问在一个窗口k内，是否存在元素的差小于t

解题思路：
维护窗口k的set。
然后查找是否存在在范围k内的元素。

遇到的问题：
思路是有的。只是一开始没有找到set可以直接进行二分查找的方法，然后自己手工模拟了一个，效率稍低，
超时了。
结果看了别人的方法，才知道有lower_bound这么一个神奇的方法。

再次阅读：
这次直接想到了之前的这种思路，因为已经知道了set的这个方法了。
然后看DISCUSS，还看到另一种思路，就是利用桶排序的思路。如下：
public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        Map<Long, Long> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            long remappedNum = (long) nums[i] - Integer.MIN_VALUE;
            long bucket = remappedNum / ((long) t + 1);
            if (map.containsKey(bucket)
                    || (map.containsKey(bucket - 1) && remappedNum - map.get(bucket - 1) <= t)
                        || (map.containsKey(bucket + 1) && map.get(bucket + 1) - remappedNum <= t))
                            return true;
            if (map.entrySet().size() >= k) {
                long lastBucket = ((long) nums[i - k] - Integer.MIN_VALUE) / ((long) t + 1);
                map.remove(lastBucket);
            }
            map.put(bucket, remappedNum);
        }
        return false;
    }
}
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> buf;
        for(int i = 0; i < nums.size(); ++i){
            if(buf.size() == k+1)buf.erase(nums[i-k-1]);
            auto it = buf.lower_bound(nums[i]-t);
            if(it != buf.end() && abs(*it - nums[i]) <= t)return true;
            buf.insert(nums[i]);
        }
        return false;
    }
};
/*
第二次做：
虽然做出来了，但是代码还没有之前的好呢。
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2) return false;

        typedef multiset<int>::iterator it;
        multiset<int> s;
        int n = nums.size();

        for (int i = 0; i <= (k < n-1 ? k : n-1); ++i) {
            it low = s.lower_bound(nums[i]-t);
            if (low != s.end() && abs(*low-nums[i]) <= t) return true;
            s.insert(nums[i]);
        }

        for (int i = k+1; i < n; ++i) {
            s.erase(s.find(nums[i-k-1]));
            it low = s.lower_bound(nums[i]-t);
            if (low != s.end() && abs(*low-nums[i]) <= t) return true;
            s.insert(nums[i]);
        }

        return false;
    }
};
/*
 * good.
 * but answer in discuss is better.
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) s.erase(nums[i-k-1]);
            auto it = s.lower_bound(nums[i]-t);
            if (it != s.end() && abs(*it-nums[i] <= t)) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
