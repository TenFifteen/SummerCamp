/**
 * Problem: Given an array of integers and a number k, the majority
 *          number is the number that occurs more than 1/k of the size
 *          of the array.
 * Solve: when gather together k different number then eliminate k number.
 *        In this way, we can limit the number to count in the end under the
 *        size of k
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: A list of integers
         * @param k: As described
         * @return: The majority number
         */
        int majorityNumber(vector<int> nums, int k) {
            unordered_map<int, int> knum;

            int cnt = 0;
            for (int num : nums) {
                if (knum.find(num) == knum.end()) {
                    ++cnt;
                }
                knum[num]++;


                if (cnt == k) {
                    vector<int> rm;
                    for (auto &p : knum) {
                        if (--p.second == 0) {
                            rm.push_back(p.first);
                            --cnt;
                        }
                    }

                    for (int r : rm) {
                        knum.erase(r);
                    }
                }
            }


            for (auto &p : knum) {
                p.second = 0;
            }

            for (int num : nums) {
                if (knum.find(num) != knum.end())
                    knum[num]++;
            }

            int ans;
            cnt = INT_MIN;
            for (auto &p : knum) {
                if (p.second > cnt) {
                    cnt = p.second;
                    ans = p.first;
                }
            }

            return ans;
        }
};

