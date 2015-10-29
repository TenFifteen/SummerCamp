/*
题目：21 % 赋值运算符重载 中等

题目大意：
实现赋值运算符的重载。

解题思路：
见代码。

遇到的问题：
一开始忘记了考虑NULL的情况了。
*/
class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (&object == this) return *this;
        if (m_pData != NULL) {
            delete m_pData;
            m_pData = NULL;
        }
        if (object.m_pData == NULL) {
            return *this;
        }
        
        int len = strlen(object.m_pData);
        m_pData = new char[len+1];
        m_pData[len] = '\0';
        for (int i = 0; i < len; ++i) {
            m_pData[i] = object.m_pData[i];
        }
        return *this;
    }
};
