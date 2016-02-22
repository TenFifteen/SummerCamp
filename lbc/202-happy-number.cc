/*
题目大意：
给定一个数字，然后不断的用其各位数字的平方和来替代它。如果最后它变成了1，那么就是happy的，
要不然就是会循环下去，那就是not happy的。

解题思路：
用一个set记录已经访问过的数字

遇到的问题：
一次通过。

再次阅读：
感觉之前做的虽然没啥问题，不过就是一个简单的对过程的模拟。
然后看了一下DICUSS中的解法，发现了一个非常有想法的解法：利用的就是类似于链表的
找环的过程中使用的快慢指针的算法。
int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}
*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        while(n != 1){
            if(us.find(n) != us.end())return false;
            us.insert(n);
            n = getBitSquare(n);
        }
        return true;
    }
    
    int getBitSquare(int n){
        int ret = 0;
        while(n){
            int cur = n % 10;
            ret += cur * cur;
            n /= 10;
        }
        return ret;
    }
};