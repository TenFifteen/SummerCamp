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
