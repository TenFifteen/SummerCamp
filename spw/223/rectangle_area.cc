#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/**
 * Problem: Find the total area covered by two rectilinear rectangles in a 2D plane.
 *          may have some overlaps.
 * Solve:  Fix one rectangle, then move the other one. Little by little I found
 *         some rules: treat all the numbers as lines vertical or horizontal lines.
 *
 *         Then I summarize the conditions that the two rectangle will overlap.
 * Tips: 1. Some intermediate results may be out of integer range.
 *       2. We can use ^ to estimate the sign of the product instead of *
 */
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int l1 = C - A;
    int l2 = G - E;
    int w1 = D - B;
    int w2 = H - F;

    int s1 = l1 * w1;
    int s2 = l2 * w2;

    int l3 = G - A;
    int l4 = E - C;
    if ((l3 ^ l4) > 0) return s1+s2;

    int w3 = H - B;
    int w4 = F - D;
    if ((w3 ^ w4) > 0) return s1+s2;

    int l = min(min(l1, l2), min(abs(l3),abs(l4)) );
    int w = min(min(w1, w2), min(abs(w3),abs(w4)) );

    return s1 - l * w + s2;

}

int main()
{
    int A, B, C, D, E, F, G, H;
    while (cin >> A >> B >> C >> D >> E >> F >> G >> H) {
        cout << computeArea(A, B, C, D, E, F, G, H) << endl;
    }

    return 0;
}

