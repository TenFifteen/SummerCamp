/**
 * Problem: Given a sorted integer array without duplicates,
 *          return the summary of its ranges.
 * Solve: 1. Iterator on the vector.
 *        2. stringstream + two pointers
 * Tips: The final range.
 */
class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> ans;
            int n = nums.size();
            if(n == 0) return ans;

            stringstream range;
            int l = nums[0], r = nums[0];
            for (int i = 1; i < n; ++i) {
                ++r;

                if (r != nums[i]) {
                    if (l == r-1) {
                        range << l;

                    } else {
                        range << l << "->" << r-1;

                    }
                    ans.push_back(range.str());
                    range.str("");
                    l = r = nums[i];

                }

            }

            if (l == r) {
                range << l;

            } else {
                range << l << "->" << r;

            }
            ans.push_back(range.str());

            return ans;

        }

};

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if (n == 0) return ans;

        int s = nums[0], e = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > e+1) {
                if (s == e) {
                    ans.push_back(to_string(s));
                } else {
                    ans.push_back(to_string(s) + "->" + to_string(e));
                }
                s = e = nums[i];
            } else {
                e++;
            }
        }

        if (s == e) {
            ans.push_back(to_string(s));
        } else {
            ans.push_back(to_string(s) + "->" + to_string(e));
        }

        return ans;
    }
};
