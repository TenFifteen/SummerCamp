#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;

/**
 * Problem: Given a list of non negative integers, arrange
 *          them such that they form the largest number.
 * Solve: the key point is implement an compare method efficiently.
 * Tips: 1. Remember the length in advance.
 *       2. Compare method may return a boolean variable. I return
 *          a integer before, but when it's to large or small, the
 *          number will truncated wrongly.
 *       3. When implement the sort method, remember to swap the
 *          length array.
 *       4. We can use stringstream and '<<' to complete the convertion
 *          from  integer to string.
 */
class Solution {
    public:
        /**
         *@param num: A list of non negative integers
         *@return: A string
         */
        string largestNumber(vector<int> &num) {
            // write your code here
            int n = num.size();
            if (n == 0) return "";


            vector<int> len(n);
            for (int i = 0; i < n; ++i) {
                len[i] = length(num[i]);
            }

            mysort(num, len, 0, n-1);
            if (num[0] == 0) return "0";

            stringstream ans;
            for (int i = 0; i < n; ++i) {
                ans << num[i];
            }
            return ans.str();
        }

        void swap(vector<int> &num, int i, int j) {
            int tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
        }

        int length(int num) {
            if (num == 0) return 1;

            int len = 0;
            while (num) {
                len++;
                num /= 10;
            }
            return len;
        }

        bool cmp(vector<int> &num, vector<int> &len, int i, int j) {
            long long a = num[i], b = num[j];
            return a * pow(10, len[j])+ b - (b * pow(10, len[i]) + a) > 0;
        }

        void mysort(vector<int> &num, vector<int> &len, int left, int right) {
            if (left >= right) return;
            int mid = (left + right) / 2;
            swap(num, mid, left);
            swap(len, mid, left);

            int last = left;
            for (int i = left+1; i <= right; ++i) {
                if (cmp(num, len, i, left) > 0) {
                    ++last;
                    swap(num, i, last);
                    swap(len, i, last);
                }
            }
            swap(num, left, last);
            swap(len, left, last);

            mysort(num, len, left, last-1);
            mysort(num, len, last+1, right);
        }
};

int main()
{
    int n = 6;
    vector<int> test(n);
    test[0] = 2147483647;
    test[1] = 2147483646;
    test[2] = 9;
    test[3] = 1;
    test[4] = 8;
    test[5] = 2147483647;
    Solution *s = new Solution();
    vector<int> len(n);
    for (int i = 0; i < n; ++i) {
        len[i] = s->length(test[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("cmp(%d, %d) = %d\n", test[i], test[j], s->cmp(test, len, i, j));
        }
    }

    cout << s->largestNumber(test) << endl;

    return 0;

}
