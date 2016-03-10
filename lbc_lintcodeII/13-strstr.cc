/*
题目大意：
判断target是否是source的一个字串。

解题思路：
暴力

遇到的问题：
这种使用指针的情况，不光要判断len是否越界，还要单独判断其是否是NULL
*/
class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (source == NULL || target == NULL) return -1;
        int lenS = strlen(source), lenT = strlen(target);
        if (lenS < lenT) return -1;
        
        for (int i = 0; i <= lenS-lenT; ++i) {
            
            bool ok = true;
            for (int j = 0; j < lenT; ++j) {
                if (target[j] != source[i+j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return i;
        }
        
        return -1;
    }
};
