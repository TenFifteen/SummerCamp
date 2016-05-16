/*
题目大意：
给定一个数组，有k中颜色，标号1-k，然后对他们进行排序。
不可以用计数排序。

解题思路：
只是没有用到计数排序的额外空间，但是还是用了计数排序的思路。

遇到的问题：
其实这个解法还是有问题的，因为有可能当前颜色计数前面的颜色的总数都没有前面颜色的种类多，
那么就会出现覆盖问题。感觉还是挺不好解决的。

其实我觉得人家不想让用计数排序的原因应该是对象有可能很大，不能随便构造呢？

可以用k/2次三路排序，不过这样就成了n*k的复杂度了。如果k很大，复杂度有些高。

当然了，可以自己手写一个快排之类的。但是快排需要额外的栈空间。
*/
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        if (k > colors.size()) sort(colors.begin(), colors.end());
        
        for (int i = 0; i < colors.size(); ++i) {
            while (colors[i] > 0) {
                int next = colors[i]-1;
                if (colors[next] > 0) {
                    colors[i] = colors[next];
                    colors[next] = -1;
                } else {
                    colors[next]--;
                    colors[i] = 0;
                }
            }
        }
        
        int index = colors.size()-1;
        for (int i = k-1; i >= 0; --i) {
            for (int j = 0; j < -colors[i]; ++j) {
                colors[index--] = i+1;
            }
        }
    }
};
