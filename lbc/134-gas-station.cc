/*
题目大意：
给定一个环形的加油站列表。给出每个加油站可以给出的油量，以及从该站到下一站所需要的油量。
问是否有一个起点可以让汽车绕着环走一圈。汽车的油罐是无限的。

解题思路：
选择一个起点，直接往前走，知道走不动了为止。然后从走不动的位置下一个位置开始继续寻找。
因为已经走过的地方都不可以为起点了。

遇到的问题：
没有问题。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        bool end = false;
        while(end == false){
            int sum = gas[start]-cost[start];
            int cur = start;
            while(sum >= 0){
                cur++;
                if(cur == gas.size()){
                    cur = 0;
                    end = true;
                }
                if(cur == start)return start;
                sum += gas[cur]-cost[cur];
            }
            start = cur+1;
            if(start == gas.size())return -1;
        }
        return -1;
    }
};