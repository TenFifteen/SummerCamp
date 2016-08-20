/**
 * Problem: You are playing the following Bulls and Cows game with your friend:
 *          You write down a number and ask your friend to guess what the number
 *          is. Each time your friend makes a guess, you provide a hint that
 *          indicates how many digits in said guess match your secret number
 *          exactly in both digit and position (called "bulls") and how many digits
 *          match the secret number but locate in the wrong position (called "cows").
 *          Your friend will use successive guesses and hints to eventually derive
 *          the secret number.
 * Solve: hash count
 * Tips: no
 */
class Solution {
    public:
        string getHint(string secret, string guess) {
            int len = secret.size();

            int a = 0, b = 0;
            int digits[10] = {0};
            for (int i = 0; i < len; ++i) {
                if (secret[i] == guess[i]) {
                    secret[i] = guess[i] = 'a';
                    ++a;
                } else {
                    digits[guess[i]-'0']++;
                }
            }

            for (int i = 0; i < len; ++i) {
                if (secret[i] >= '0' && secret[i] <= '9') {
                    if (digits[secret[i]-'0']-- > 0) {
                        ++b;
                    }
                }
            }

            return to_string(a)+"A"+to_string(b)+"B";
        }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> src(10, 0), dst(10, 0);
        int n = secret.size();

        int cntA = 0;
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) ++cntA;
            else {
                src[secret[i]-'0']++;
                dst[guess[i]-'0']++;
            }
        }

        int cntB = 0;
        for (int i = 0; i < 10; ++i) {
            cntB += min(src[i], dst[i]);
        }

        return to_string(cntA)+"A"+to_string(cntB)+"B";
    }
};
