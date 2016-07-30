/*
题目大意：
给定一个环形的加油站列表。给出每个加油站可以给出的油量，以及从该站到下一站所需要的油量。
问是否有一个起点可以让汽车绕着环走一圈。汽车的油罐是无限的。

解题思路：
选择一个起点，直接往前走，知道走不动了为止。然后从走不动的位置下一个位置开始继续寻找。
因为已经走过的地方都不可以为起点了。

遇到的问题：
没有问题。

再次阅读：
感觉这个题目的解法一已经是最优了，因为只遍历了一遍，空间复杂度为O(1)
但是之前写的代码稍微可以再精简一下。
看到DISCUSS中还有一些比较奇怪的解法，也没有细看。
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
/*
第二次做：
思路没有任何问题，不过总是感觉代码写起来特别费劲呢。
是不是今天刷的太多了啊。
还有就是对于只有一个station的情形，也要求可以走一圈才可以。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() < 1) return 0;

        int start = 0;
        while (start < gas.size()) {
            int cur = start, left = gas[start]-cost[start], steps = 0;
            while (left >= 0 && steps < gas.size()) {
                cur++;
                cur %= gas.size();
                left += gas[cur] - cost[cur];
                steps++;
            }
            if (steps == gas.size()) return start;
            start += steps+1;
        }

        if (start < gas.size()) return start;
        return -1;
    }
};
/*
 * must be cautious
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 1) return gas[0] >= cost[0] ? 0 : -1; // special case

        int index = 0;
        while (true) {
            bool isOk = true;
            int now = 0, next;
            for (int i = 0; i < gas.size(); ++i) {
                int realIndex = (index + i) % gas.size();
                now += gas[realIndex] - cost[realIndex];
                if (now < 0) {
                    isOk = false;
                    next = (realIndex + 1) % gas.size();
                    break;
                }
            }

            if (isOk) return index;
            if (next <= index) return -1;
            index = next;
        }
    }
};
