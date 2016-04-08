/**
 * Problem: There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *          You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station
 *          i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *          Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * Solve: 1. if the total gas > total cost, there must be a solution.
 * Tips: see comments below.
 */
class Solution {
    public:
        /**
         * @param gas: a vector of integers
         * @param cost: a vector of integers
         * @return: an integer
         */
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            int n = gas.size();

            int sumLeft = 0, hold = 0, start = 0;
            for (int i = 0; i < n; ++i) {
                int nowLeft = gas[i] - cost[i];

                sumLeft += nowLeft;
                hold += nowLeft;

                // if the i+1 is the first station we can't reach from
                // start, then start from the station between (start, i] can't reach
                // i+1 either
                if (hold < 0) {
                    start = i + 1;
                    hold = 0;
                }
            }

            return sumLeft < 0 ? -1 : start;
        }
};
