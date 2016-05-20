/*
题目大意：
给定一个环形，里面都是加油站，每个加油站提供多少gas和走到下一个加油站
需要多少cost。问能否找到一个起点，可以走完所有的加油站。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        if (gas.size() == 0) return -1;
        if (gas.size() == 0) return 0;
        
        int n = gas.size(), index = 0;
        while (index < n) {
            int cur = index, total = 0, cnt = 0;
            while (total >= 0 && cnt <= n) {
                total += gas[cur];
                total -= cost[cur];
                
                cur++;
                cur %= n;
                
                cnt++;
            }
            
            if (cnt > n) return index;
            index += cnt;
        }
        
        return -1;
    }
};
