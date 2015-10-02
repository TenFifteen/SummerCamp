/*
题目：29 % 加油站 中等

题目大意：
给定一个数组，表示加油站的油量以及到下一站的需要消耗的油量。问能否找到一个起点，使之可以绕所有加油站一周？

解题思路：
就是走过的地方就不需要走了。

遇到的问题：
没有问题。
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
        int start = 0;
        while (true) {
            int cur = start;
            int sum = gas[cur] - cost[cur];
            int cnt = 0;
            while (sum >= 0) {
                cur++;
                if (cur == gas.size()) {
                    cur = 0;
                }
                sum += gas[cur] - cost[cur];
                cnt++;
                if (cnt == gas.size()) return start;
            }
            if (cur < start) return -1;
            start = cur+1;
            if (start == gas.size()) {
                return -1;
            }
        }
    }
};
