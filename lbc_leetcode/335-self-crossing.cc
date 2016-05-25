/*
题目大意：
给定一个整数数组，都是正数。
表示一个点的行走轨迹。从(0,0)开始，分别向上左下右行走。
问是否有自己相交的地方。

解题思路：
没有相交的情形只有三个，分别是圈越画越小，圈越画越大，圈先大后小。
然后对这三种情况分别处理。

遇到的问题：
又是一个完全没有思路的题目。
还是看了别人题解之后才想明白的。而且程序也调试了很久。
*/
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() < 4) return false;
        
        deque<int> deq;
        for (int i = 0; i < 3; ++i) deq.push_back(x[i]);
        
        bool inc = x[2] > x[0] ? true : false;
        bool last = false;
        
        for (int i = 3; i < x.size(); ++i) {
            int dsize = deq.size();
            if (x[i] > deq[dsize-2]) {
                cout << "inc" << endl;
                if (inc == false) return true;
            } else {
                if (inc == true) {
                    last = true;
                    inc = false;
                } else if (last == true) {
                    last = false;
                    if (dsize > 4 && x[i]+deq[dsize-4] >= deq[dsize-2] && deq[dsize-1]+deq[dsize-5] >= deq[dsize-3]) return true;
                    if (dsize > 3 && deq[dsize-1]==deq[dsize-3] && x[i]+deq[dsize-4] >= deq[dsize-2]) return true;
                } else {
                    if (x[i] == deq[dsize-2] && deq[dsize-1] == deq[dsize-3]) return true;
                }
            }
            
            deq.push_back(x[i]);
            while (deq.size() > 5) deq.pop_front();
        }
        
        return false;
    }
};