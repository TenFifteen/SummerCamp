/*
题目大意：
找到第n个丑数。

解题思路：
在已有k个丑数的前提下，找第k+1个丑数的方式：
分别找到乘以2、3、5三个数组成的最小的那个丑数，然后就是这个丑数了。

遇到的问题：
这个题目是在编程之美中看到的。竟然现在就用到了。

再次阅读：
之前以为这就是最优的解法了，结果后来遇到了一个更好的。不过只是针对这个题目来讲的话，
还有一种动归的方式挺不错的：
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
};
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        
        set<int> s;
        s.insert(1);
        
        for (int i = 1; i < n; ++i) {
            int next = *s.rbegin() + 1;
            int tmp = *s.lower_bound((next+1)/2) * 2;
            tmp = min(tmp, *s.lower_bound((next+2)/3) * 3);
            tmp = min(tmp, *s.lower_bound((next+4)/5) * 5);
            
            s.insert(tmp);
        }
        
        return *s.rbegin();
    }
};
/*
第二次做：
算法没有太大问题了。
不过就是有越界的问题出现了。。。
所以最后用的都是long long了。
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> mul = {2, 3, 5};
        
        vector<queue<long long>> vq(3);
        vq[0].push(2);
        vq[1].push(3);
        vq[2].push(5);
        
        long long cur = 1, cnt = 1;
        while (cnt++ < n) {
            int index = 0;
            for (int i = 1; i < 3; ++i) {
                if (vq[i].front() < vq[index].front()) index = i;
            }
            
            cur = vq[index].front(); vq[index].pop();
            for (int i = index; i < 3; ++i) {
                vq[i].push(cur * mul[i]);
            }
        }
        return cur;
    }
};