/*
题目大意：
给定一组飞机的起落时间，问天上同时存在的飞机数量最多是多少？

解题思路：
拆成起飞和降落，直接排序遍历就行了。

遇到的问题：
没有。
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
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int n = airplanes.size();
        if (n == 0) return 0;
        
        vector<pair<int, int>> lines(n*2);
        for (int i = 0; i < n; ++i) {
            lines[i*2] = make_pair(airplanes[i].start, 1);
            lines[i*2+1] = make_pair(airplanes[i].end, -1);
        }
        
        sort(lines.begin(), lines.end());
        
        int ans = 0, now = 0;
        for (auto line : lines) {
            if (line.second < 0) now--;
            else now++;
            ans = max(ans, now);
        }
        
        return ans;
    }
};