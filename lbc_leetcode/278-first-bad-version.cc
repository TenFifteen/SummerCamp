/*
题目大意：
有一系列的软件版本，其中从某一版本处就开始出现了问题，而之后的所有版本就都有问题了。
有一个函数可以判断某一版本是否是有问题的。
然后找到第一个有问题的版本。

解题思路：
比较明显的二分查找。

遇到的问题：
没有问题。

再次阅读：
典型的二分，没有问题。
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (isBadVersion(mid)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return ans;
    }
};
/*
第二次做：
二分，没有太大问题。
二分最重要的一点就是决定==时候的方向问题，根据这个方向选择mid的计算。
另外就是mid的计算有两个问题，一个是相加溢出，一个是相减溢出。所以都要考虑一下。
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + ((right-left)>>1);
            if (isBadVersion(mid)) right = mid;
            else left = mid+1;
        }
        return left;
    }
};
/*
 * ok
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1, right = n; // will overflow.
        while (left < right) {
            int mid = (left + right) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
