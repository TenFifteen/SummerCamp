/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
/**
 * Problem: Given an interval list which are flying and landing time
 *          of the flight. How many airplanes are on the sky at most?
 *          If landing and flying happens at the same time, we consider
 *          landing should happen at first.
 * Solve: split the interval into begin and end, then sort them together.
 *        That is, to see in the timeline, when the fly and land occur,
 *        then traversal all the event from first plane flying to the last
 *        plane landing.
 * Tips: see comments below.
 */
class Solution {
    private:
        struct line{
            int t;
            bool isFly;

            line(int t, bool i): t(t), isFly(i) {}

            bool operator < (const line &a) const {
                if (t < a.t) {
                    return true;
                } else if (t > a.t) {
                    return false;
                } else {
                    // the land must come ahead the fly
                    return isFly == false;
                }
            }
        };
    public:
        /**
         * @param intervals: An interval array
         * @return: Count of airplanes are in the sky.
         */
        int countOfAirplanes(vector<Interval> &airplanes) {
            vector<line> lines;

            for (auto in : airplanes) {
                lines.push_back(line(in.start, true));
                lines.push_back(line(in.end, false));
            }

            sort(lines.begin(), lines.end());

            int cnt = 0;
            int ans = 0;
            for (auto l : lines) {
                if (l.isFly) {
                    cnt++;
                    ans = max(ans, cnt);
                }
                else cnt--;
            }

            return ans;
        }
};
