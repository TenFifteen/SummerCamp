/*
题目大意：
求丑数

解题思路：
队列

遇到的问题：
一开始忘记了初始化队列，然后是忘记了ans是long long类型
*/
class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        if (k < 1) return 0;
        
        vector<int> primes = {3,5,7};
        vector<queue<long long>> vq(3);
        for (int i = 0; i < 3; ++i) {
            vq[i].push(primes[i]);
        }
        
        long long ans;
        for (int i = 1; i <= k; ++i) {
            int index = 0;
            for (int i = 1; i < 3; ++i) {
                if (vq[i].front() < vq[index].front()) index = i;
            }
            
            ans = vq[index].front(); vq[index].pop();
            for (int j = index; j < 3; ++j) {
                if (vq[j].size() < k-i) vq[j].push(ans*primes[j]);
            }
        }
        
        return ans;
    }
};