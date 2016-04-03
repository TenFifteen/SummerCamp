/**
 * Problem: Write a method to replace all spaces in a string with %20.
 *          The string is given in a characters array, you can assume
 *          it has enough space for replacement and you are given the
 *          true length of the string.
 * Solve: from the end to the begin
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param string: An array of Char
         * @param length: The true length of the string
         * @return: The true length of new string
         */
        int replaceBlank(char string[], int length) {
            // Write your code here
            int newLen = length;
            for (int i = 0; i < length; ++i) {
                if (string[i] == ' ') newLen += 2;
            }

            for (int i = newLen - 1, j = length - 1; i >= 0; i--, j--) {
                if (string[j] == ' ') {
                    string[i--] = '0';
                    string[i--] = '2';
                    string[i] = '%';
                } else {
                    string[i] = string[j];
                }
            }

            return newLen;
        }
};
