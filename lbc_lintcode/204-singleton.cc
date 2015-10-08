/*
题目：33 % 单例 容易

题目大意：
实现单例模式

解题思路：
这是考察OOD编程技巧，不属于算法范畴。但是我还是没有写对，参考的别人的。

遇到的问题：
不过正好发现了一个不错的开源项目，是别人整理的Lintcode上的解题思路。感觉非常好，一定要好好读一下
https://github.com/kamyu104/LintCode
*/
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution* _instance = new Solution();
        return _instance;
    }
private:
    //std::mutex mtx;
    Solution(){}
    virtual ~Solution(){}
    //static Solution * _instance;
};
