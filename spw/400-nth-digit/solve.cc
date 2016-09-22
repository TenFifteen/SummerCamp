class Solution {
public:
    int findNthDigit(int n) {
        long long cnt = 1, p = 9;
        while (n > p*cnt) {
            n -= p*cnt;

            ++cnt;
            p *= 10;
        }
        p /= 9;

        --n;
        long long pos = n / cnt, aside = n % cnt;
        long long num = p + pos;

        long long ans = num / p;
        while (aside) {
            p /= 10;

            ans = num / p % 10;
            aside--;
        }

        return ans;
    }
};
