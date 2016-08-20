/*
题目大意：
给定一个数字n，将其表示成平方和的形式，问最少用多少个平方和

解题思路：
动态规划

遇到的问题：
没有问题。

再次阅读：
虽然看到之前的代码，感觉已经很不错了。
但是看到DISCUSS，看到了好多更好的解：
1，动归的简洁解法：
class Solution
{
public:
    int numSquares(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        // cntPerfectSquares[i] = the least number of perfect square numbers
        // which sum to i. Note that cntPerfectSquares[0] is 0.
        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // For each i, it must be the sum of some number (i - j*j) and
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++)
            {
                cntPerfectSquares[i] =
                    min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
            }
        }

        return cntPerfectSquares.back();
    }
};
2，动归的静态优化：
class Solution
{
public:
    int numSquares(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        // cntPerfectSquares[i] = the least number of perfect square numbers
        // which sum to i. Since cntPerfectSquares is a static vector, if
        // cntPerfectSquares.size() > n, we have already calculated the result
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});

        // While cntPerfectSquares.size() <= n, we need to incrementally
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }

            cntPerfectSquares.push_back(cntSquares);
        }

        return cntPerfectSquares[n];
    }
};
3，是一种数学方法，就不贴代码了，毕竟我也不会
4，BFS的思路，就是把每个数当做一个节点，然后如果两个数之间的差是一个完全平方数，则连一条边；然后从0进行搜索就行了，
直到搜索到n.
class Solution
{
public:
    int numSquares(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        // perfectSquares contain all perfect square numbers which
        // are smaller than or equal to n.
        vector<int> perfectSquares;
        // cntPerfectSquares[i - 1] = the least number of perfect
        // square numbers which sum to i.
        vector<int> cntPerfectSquares(n);

        // Get all the perfect square numbers which are smaller than
        // or equal to n.
        for (int i = 1; i*i <= n; i++)
        {
            perfectSquares.push_back(i*i);
            cntPerfectSquares[i*i - 1] = 1;
        }

        // If n is a perfect square number, return 1 immediately.
        if (perfectSquares.back() == n)
        {
            return 1;
        }

        // Consider a graph which consists of number 0, 1,...,n as
        // its nodes. Node j is connected to node i via an edge if
        // and only if either j = i + (a perfect square number) or
        // i = j + (a perfect square number). Starting from node 0,
        // do the breadth-first search. If we reach node n at step
        // m, then the least number of perfect square numbers which
        // sum to n is m. Here since we have already obtained the
        // perfect square numbers, we have actually finished the
        // search at step 1.
        queue<int> searchQ;
        for (auto& i : perfectSquares)
        {
            searchQ.push(i);
        }

        int currCntPerfectSquares = 1;
        while (!searchQ.empty())
        {
            currCntPerfectSquares++;

            int searchQSize = searchQ.size();
            for (int i = 0; i < searchQSize; i++)
            {
                int tmp = searchQ.front();
                // Check the neighbors of node tmp which are the sum
                // of tmp and a perfect square number.
                for (auto& j : perfectSquares)
                {
                    if (tmp + j == n)
                    {
                        // We have reached node n.
                        return currCntPerfectSquares;
                    }
                    else if ((tmp + j < n) && (cntPerfectSquares[tmp + j - 1] == 0))
                    {
                        // If cntPerfectSquares[tmp + j - 1] > 0, this is not
                        // the first time that we visit this node and we should
                        // skip the node (tmp + j).
                        cntPerfectSquares[tmp + j - 1] = currCntPerfectSquares;
                        searchQ.push(tmp + j);
                    }
                    else if (tmp + j > n)
                    {
                        // We don't need to consider the nodes which are greater ]
                        // than n.
                        break;
                    }
                }

                searchQ.pop();
            }
        }

        return 0;
    }
};
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i*i <= n; i++) {
            squares.push_back(i*i);
        }

        int k = squares.size();
        if (squares[k-1] == n) return 1;

        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = i+1;
        }
        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (squares[i] < j+1) {
                    dp[j] = min(dp[j], dp[j-squares[i]] + 1);
                } else if (squares[i] == j+1) {
                    dp[j] = 1;
                }
            }
        }

        return dp[n-1];
    }
};
/*
第二次做：
这次竟然没有想到怎么优化空间。
结果空间用超了。
看了一下之前的解法才恍然大悟，这种的依赖是可以优化的。。。
总结一下可以优化空间的问题一般是横着，或者竖着看依赖层不超过两层的都可以优化空间。
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares, dp(n+1, INT_MAX);
        for (int i = 1; n / i >= i; ++i) squares.push_back(i*i);

        for (int i = 0; i <= n; ++i) dp[i] = i;
        for (int k = 1; k < squares.size(); ++k) {
            for (int i = 1; i <= n; ++i) {
                if (i >= squares[k]) dp[i] = min(dp[i], dp[i-squares[k]]+1);
            }
        }

        return dp[n];
    }
};
/*
 * ok. but there are some good answers in discuss.
 */
class Solution {
public:
    int numSquares(int n) {
        if (n < 1) return 0;
        vector<int> squares;
        for (int i = 1; n / i >= i; ++i) squares.push_back(i*i);
        vector<int> dp(n+1);
        for (int i = 1; i <= n; ++i) dp[i] = i;
        for (int j = 1; j < squares.size(); ++j) {
            for (int i = 1; i <= n; ++i) {
                if (i >= squares[j]) dp[i] = min(dp[i-squares[j]]+1, dp[i]);
            }
        }
        return dp[n];
    }
};

