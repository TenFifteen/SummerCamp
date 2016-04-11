#include <iostream>


using namespace std;

/**
 * Problem:
 */
/**
 **@param n, m: Two integer
 **@param i, j: Two bit positions
 **return: An integer
 **/
int updateBits(int n, int m, int i, int j) {
    if (i > j) {
        int tmp = i;
        i = j;
        j = tmp;

    }

    int mask;
    if (j == 31) {
        mask = ((1 << i) - 1) ^ (-1);
    } else {
        mask = ((1 << i) - 1) ^ ((1 << j+1) - 1);
    }
    n &= ~mask;
    n |= m << i;

    return n;
}

int main()
{
    int n, m, i, j;
    while (cin >> n >> m >> i >> j) {
        cout << updateBits(n, m, i, j) << endl;
    }
}
