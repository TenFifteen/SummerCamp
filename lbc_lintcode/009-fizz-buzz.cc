/*
题目：Fizz Buzz 容易

题目大意；
输出1-n之间的数，如果数可以被3整出就输出fizz；被5整除就输出buzz；
同时被两个整除就是fizz buzz

解题思路：
直接输出

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * param n: As description.
     * return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> results;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                results.push_back("fizz buzz");
            } else if (i % 5 == 0) {
                results.push_back("buzz");
            } else if (i % 3 == 0) {
                results.push_back("fizz");
            } else {
                results.push_back(to_string(i));
            }
        }
        return results;
    }
};