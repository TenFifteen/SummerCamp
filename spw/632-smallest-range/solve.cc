/**
 * Problem: You have k lists of sorted integers in ascending order.
 *          Find the smallest range that includes at least one number
 *          from each of the k lists.
 *
 *           We define the range [a,b] is smaller than range [c,d] if
 *           b-a < d-c or a < c if b-a == d-c.
 *
 *           Example 1:
 *           Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 *           Output: [20,24]
 *           Explanation:
 *           List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 *           List 2: [0, 9, 12, 20], 20 is in range [20,24].
 *           List 3: [5, 18, 22, 30], 22 is in range [20,24].
 * Solve: heap
 * Tips: see comments below.
 */
class Solution {
    private:
        // typedef
        typedef vector<int>::iterator It;
        struct cmp
        {
            bool operator()(const pair<It, It> &a, const pair<It, It> &b) {
                return *(a.first) > *(b.first);
            }
        };
    public:
        vector<int> smallestRange(vector<vector<int>>& nums) {
            priority_queue<pair<It, It>, vector<pair<It, It>>, cmp> heap;
            int maxNum = INT_MIN;
            for (auto &vec : nums) {
                heap.push(make_pair(vec.begin(), vec.end()));
                maxNum = max(maxNum, vec.front());
            }

            int minNum = *(heap.top().first);
            int range = maxNum - minNum;
            vector<int> res = {minNum, maxNum};

            while(true) {
                auto itPair = heap.top();
                heap.pop();

                minNum = *(itPair.first);
                //cout << minNum << endl;
                if (maxNum - minNum < range) {
                    range = maxNum - minNum;
                    res[0] = minNum;
                    res[1] = maxNum;
                }

                // first ++
                if (++(itPair.first) != itPair.second) {
                    // update maxNum time
                    maxNum = max(maxNum, *(itPair.first));
                    heap.push(itPair);
                } else {
                    break;
                }
            }

            return res;
        }
};
