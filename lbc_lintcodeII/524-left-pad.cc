/*
题目大意：
给定一个字符串，将其左边填充字符，使其达到要求的长度。

解题思路：
见代码。

遇到的问题：
没有问题。
*/
class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        if (originalStr.size() >= size) return originalStr;
        return string(size-originalStr.size(), padChar) + originalStr;
    }
};