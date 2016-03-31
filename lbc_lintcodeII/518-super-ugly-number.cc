/*
题目大意：
计算超级丑数。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        vector<queue<int>> vq(primes.size());
        
        for (int i = 0; i < primes.size(); ++i) {
            vq[i].push(primes[i]);
        }
        
        int cur = 1;
        while (n-- > 1) {
            int index = 0;
            for (int i = 1; i < vq.size(); ++i) {
                if (vq[i].front() < vq[index].front()) index = i;
            }
            
            cur = vq[index].front();
            vq[index].pop();
            
            for (int i = index; i < vq.size(); ++i) {
                vq[i].push(primes[i] * cur);
            }
        }
        
        return cur;
    }
};