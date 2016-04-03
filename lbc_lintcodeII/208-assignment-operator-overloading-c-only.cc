/*
题目大意：
重载赋值操作符

解题思路：
见代码。

遇到的问题：
没有。
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
        
        if (m_pData != NULL) free(m_pData);
        
        if (object.m_pData != NULL) {
            int len = strlen(object.m_pData);
            m_pData = (char *)malloc((len+1)*sizeof(char));
            memcpy(m_pData, object.m_pData, len+1);
        } else {
            m_pData = NULL;
        }
        
        return *this;
    }
};