#include <cstdio>
#include <vector>
#include <map>

using namespace std;

/**
 ** Definition for a point.
 **/
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

/**
 * if gcd(5, 10), then we have b != 0, gcd(10, 5%10)(that is exchange them);
 * if gcd(5, -10), gcd(-10, 5%(-10))=gcd(-10, -5)=gcd(-5, -10%(-5)), in mod
 * we use the sign of divdend as the sign of result.
 */
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
/**
 * Problem: given n points on a 2D plane, find the maximum number of points that lie on
 *          the same straight line.
 * Solve: traverse every point, find the each points count of all the lines cross it.
 * Tips: 1. notice the duplicate points and vertical line.
 *       2. if we use double as key of map, we should carefully calculate the dy/dx
 *          we can't let double key = dy/dx, but key = (double)dy/dx
 *       3. when we use pair and calculate gcd, how about a < b?
 *          5 -10, then g = -5, so we get -1 2
 *          -5 10, then g = 5, so we also get -1 2
 */
int maxPoints(vector<Point>& points) {
	int n = points.size();
	int maxp = 0;
	for (int i = 0; i < n; ++i) {
		int duplicates = 0;
		int verticals = 0;
		map<pair<int, int>, int> slops;
		for (int j = i + 1; j < n; ++j) {
			int dx = points[i].x - points[j].x;
			int dy = points[i].y - points[j].y;

			if (dx == 0 && dy == 0) {
				duplicates++;
			} else if (dx == 0) {
				verticals++;
			} else {
				int g = gcd(dx, dy);
				dx /= g;
				dy /= g;
				slops[make_pair(dx, dy)]++;
			}
		}
		int m = verticals;
		for (map<pair<int, int>,int>::iterator it = slops.begin(); it != slops.end(); ++it) {
			m = max(m, it->second);
		}
		//printf("[%d, %d] = %d\n", points[i].x, points[i].y, m);
		//printf("verticals = %d\n", verticals);
		//printf("duplicates = %d\n", duplicates);
		maxp = max(maxp, duplicates+1+m);
	}

	return maxp;
}

int main()
{
	printf("gcd(%d,%d)=%d\n", 10, 5, gcd(10 ,5));
	printf("gcd(%d,%d)=%d\n", 5, 10, gcd(5 ,10));
	printf("gcd(%d,%d)=%d\n", -10, 5, gcd(-10 ,5));
	printf("gcd(%d,%d)=%d\n", 10, -5, gcd(10 ,-5));
	Point a(84, 250);
	Point b(0, 0);
	Point c(1, 0);
	Point d1(0, -70);
	Point d2(0, -70);
	Point e(1, -1);
	Point f(21, 10);
	Point g(42, 90);
	Point h(-42, -230);

	vector<Point> points(9);
	points[0] = a;
	points[1] = b;
	points[2] = c;
	points[3] = d1;
	points[4] = d2;
	points[5] = e;
	points[6] = f;
	points[7] = g;
	points[8] = h;
	printf("The max points in a line are %d\n", maxPoints(points));

	return 0;
}

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    int gcd(int a, int b) {
        if (a == 0) return b;

        return gcd(b%a, a);
    }
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n < 3) return n;

        int ans = 2;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> cnt;
            int v = 0, h = 0, dup = 1;
            for (int j = i+1; j < n; ++j) {
                // can use dx dy for short
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    ++dup;
                } else if (points[j].x == points[i].x) {
                    ++v;
                } else if (points[j].y == points[i].y) {
                    // need not, because we can judge in gcd
                    ++h;
                } else {
                    int dx = points[j].x-points[i].x, dy = points[j].y-points[i].y;
                    int g = gcd(dy, dx);
                    cnt[make_pair(dy/g, dx/g)]++;
                }
            }

            int now = max(v, h);
            for (auto c : cnt) {
                now = max(now, c.second);
            }

            ans = max(ans, now+dup);
        }

        return ans;
    }
};
