#include <iostream>

using namespace std;
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


/**
 * Problem: Given n points on a 2D plane, find the maximum number of
 *          points that lie on the same straight line.
 * Solve: Traversal all the points, count all the counts on every slope,
 *        find the max.
 * Tips: You must consider the duplicates aside.
 */
class Solution {
    public:
        /**
         * @param points an array of point
         * @return an integer
         */
        int maxPoints(vector<Point>& points) {
            // Write your code here
            int ans = 0;

            int n = points.size();
            for (int i = 0; i < n; ++i) {
                map<pair<int, int>, int> slopes;
                int vertical = 0;
                int level = 0;
                int duplicates = 1;
                for (int j = i+1; j < n; ++j) {
                    int dx = points[j].x - points[i].x;
                    int dy = points[j].y - points[i].y;

                    if (dx == 0 && dy == 0) {
                        ++duplicates;
                    } else if (dx == 0) {
                        vertical++;
                    } else if (dy == 0) {
                        level++;
                    } else {
                        int s = gcd(dy, dx);
                        pair<int, int> slope(dy/s, dx/s);
                        slopes[slope]++;
                    }
                }

                ans = max(ans, vertical + duplicates);
                ans = max(ans, level + duplicates);
                for (map<pair<int,int>, int>::iterator it = slopes.begin(); it != slopes.end(); ++it) {
                    ans = max(ans, it->second+duplicates);
                }
            }

            return ans;
        }
    private:
        int gcd(int y, int x) {
            if (y % x == 0) return x;
            return gcd(x, y%x);
        }
};

int main()
{

}
