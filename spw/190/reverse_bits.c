/**
 * Problem: Reverse bits of a given 32 bits unsigned integer.
 * Solve: use another variable.
 * Tips: no
 */
uint32_t reverseBits(uint32_t n) {
	uint32_t ans = 0;

	int i = 0;
	while (i < 32) {
		ans = (ans << 1) | (n & 0x1);
		n >>= 1;
		++i;
	}
	return ans;
}
