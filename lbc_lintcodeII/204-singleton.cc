/*
题目大意：
实现一个singleton的class

解题思路：
见代码。

遇到的问题：
又没有写出来。
看来对于C++还是不够了解啊。
*/
class Solution {
    Solution(){}
    ~Solution(){}
    
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution *_instance = new Solution();
        return _instance;
    }
};