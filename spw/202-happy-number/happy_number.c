/**
 * Problem: replace a number by the sum of the squares of its digits, repeat this proecess
 *          until it equals 1. Then we call it a happy number because it becomes stable.
 * Solve: more details see https://en.wikipedia.org/wiki/Happy_number
 * Tips: no
 */
bool isHappy(int n) {
	if (n < 4) return n == 1;
	int magic = 4;
	for(;;) {
		if (n == magic) return false;
		else if (n == 1) return true;
		int next = 0;
		while (n) {
			next += (n%10)*(n%10);
			n /= 10;
		}
		n = next;
	}
}

class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            int next = 0;
            while (n) {
                int digit = n % 10;
                next += digit * digit;

                n /= 10;
            }

            n = next;
        }

        return n == 1;
    }
};
