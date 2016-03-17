/*
题目大意：
给定一个数组，其中的众数的数量大于n/k，问该数是啥？

解题思路：
用一个k大小的hash

遇到的问题：
hash容器还是不能一边遍历一边删除。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> hash;
        for (auto n : nums) {
            if (hash.find(n) != hash.end()) hash[n]++;
            if (hash.size() < k) hash[n] = 1;
            else {
                vector<int> del;
                for (auto &p : hash) {
                    p.second--;
                    if (p.second == 0) del.push_back(p.first);
                }
                for (auto d : del) {
                    hash.erase(d);
                }
            }
        }
        
        int cnt = 0, ans;
        for (auto &p : hash) p.second = 0;
        for (auto n : nums) {
            if (hash.find(n) != hash.end()) hash[n]++;
            if (hash[n] > cnt) {
                ans = n;
                cnt = hash[n];
            }
        }
        
        return ans;
    }
};
