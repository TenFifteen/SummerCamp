/*
题目：22 % 数飞机 中等

题目大意：
给定一组区间，表示飞机的起飞和降落时间。问天空中同时最多有多少飞机。
如果起飞和降落同时发生，则降落优先

解题思路：
将所有飞机的起飞和降落时间算作单独的事件，然后进行排序。再遍历。

遇到的问题：
没有问题。
*/
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    struct line {
        int t;
        bool fly;
        line(int time, bool isfly) {
            t = time;
            fly = isfly;
        }
        bool operator< (const line &a) const {
            if (t < a.t) {
                return true;
            } else if (t > a.t) {
                return false;
            } else {
                return fly == false;
            }
        }
    };
    
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int ans = 0;
        if (airplanes.size() == 0) return 0;
        vector<line> v;
        for (auto a : airplanes) {
            v.push_back(line(a.start, true));
            v.push_back(line(a.end, false));
        }
        int now = 0;
        sort(v.begin(), v.end());
        for (auto l : v) {
            if (l.fly) {
                now++;
                if (now > ans) {
                    ans = now;
                }
            } else {
                now--;
            }
        }
        return ans;
    }
};
