/**
 * Problem: Given an array nums, there is a sliding window of size k  which is
 *          moving from the very left of the array to the very right. You can
 *          only see k numbers in the window. Each time the sliding window moves
 *          right by one position.
 * Solve: Sustain a sequence of monotone increasing order using a dequeue.
 * Tips: Save index instead of numbers in the dequeue.
 *       Push index to the back of the dequeue every time.
 */
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> incSeq;
            vector<int> ans;

            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                if (!incSeq.empty() && incSeq.front() == i-k) incSeq.pop_front();
                while (!incSeq.empty() && nums[incSeq.back()] <= nums[i]) {
                    incSeq.pop_back();
                }

                incSeq.push_back(i);
                if (i >= k-1) {
                    ans.push_back(nums[incSeq.front()]);
                }
            }
            return ans;
        }

};

class Solution {
    struct classCmp {
        bool operator() (const int& a, const int& b) const
        {
            return a > b;
        }
    };
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        if (n == 0) return ans;

        multiset<int, classCmp> win;
        for (int i = 0; i < n; ++i) {
            win.insert(nums[i]);
            if (win.size() == k) {
                ans.push_back(*win.begin());
                win.erase(win.lower_bound(nums[i+1-k]));
            }
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> win;

        // use win to save the window index of numbers
        for (int i = 0; i < n; ++i) {
            if (win.front() <= i-k) win.pop_front();
            while (!win.empty() && nums[i] > nums[win.back()]) win.pop_back();
            win.push_back(i);

            if (i >= k-1) {
                ans.push_back(nums[win.front()]);
            }
        }

        return ans;
    }
};
