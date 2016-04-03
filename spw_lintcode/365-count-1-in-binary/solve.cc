/**
 * Problem: Count how many 1 in binary representation of a 32-bit integer.
 * Solve: eliminate a 1 every time.
 * Tips: no
 */
int countOnes(int num) {
    int cnt = 0;
    while (num) {
        num &= num - 1;
        cnt++;

    }

    return cnt;

}
