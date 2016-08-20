/*
 * ok.
 * /
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
unordered_map<int, int> um;
map<int, int> m;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        if (um.find(val) != um.end()) return;

        int left = um.find(val-1) == um.end() ? 0 : um[val-1];
        int right = um.find(val+1) == um.end() ? 0 : um[val+1];
        if (left) m.erase(val-left);
        if (right) m.erase(val+1);

        int len = left + right + 1;

        um[val] = len;
        um[val-left] = len;
        um[val+right] = len;
        m[val-left] = len;
    }

    vector<Interval> getIntervals() {
        vector<Interval> ans;
        for (auto p : m) {
            ans.push_back(Interval(p.first, p.first+p.second-1));
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
