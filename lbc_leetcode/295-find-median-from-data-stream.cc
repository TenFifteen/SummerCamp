/*
题目大意：
给定一个数字序列，和查询函数。求数列的动态的中位数。

解题思路：
将数字大的一半放到s1，小的一半放到s2.这样就可以用O(1)的时间复杂度求得中位数了。

遇到的问题：
一开始忘记了将set设置为multiset了。所以除了莫名其妙的错误，还去debug了半天。

再次阅读：
感觉自己对这道题的解法就是怎么想的就是怎么写的，一点技巧都没有用到啊。
然后看到DISCUSS中有一个及其简单的解法，思想一样，但是过程简单到不知道哪里去了：
class MedianFinder {
    priority_queue<long> small, large;
public:

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};
*/
class MedianFinder {
private:
    multiset<int> s1, s2; // s1 large, s2 small
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (s1.size() == 0) {
            s1.insert(num);
        } else if (s2.size() == 0) {
            int tmp = *s1.begin();
            if (tmp < num) {
                s1.erase(s1.find(tmp));
                s1.insert(num);
                s2.insert(tmp);
            } else {
                s2.insert(num);
            }
        } else {
            if (s1.size() > s2.size()) {
                //add to s2
                int tmp = *s1.begin();
                if (num > tmp) {
                    s1.erase(s1.find(tmp));
                    s1.insert(num);
                    s2.insert(tmp);
                } else {
                    s2.insert(num);
                }
            } else {
                //add to s1
                int tmp = *s2.rbegin();
                if (num < tmp) {
                    s2.erase(s2.find(tmp));
                    s2.insert(num);
                    s1.insert(tmp);
                } else {
                    s1.insert(num);
                }
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (s1.size() > s2.size()) {
            return *s1.begin();
        } else {
            double sum = *s1.begin() + *s2.rbegin();
            return sum / 2;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
/*
第二次做：
虽然我觉得这次写的还算是可以，但是看了DISCUSS中的那种只用了两个
pq就解决问题的思路，确实是天外有天啊。而且，通过加一个负号，瞬间
把一个最大堆变成了最小堆。。。。
*/
class MedianFinder {
    multiset<int> low, up;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        low.insert(num);
        if (low.size() > up.size()) {
            int cur = *low.rbegin();

            up.insert(cur);
            low.erase(low.find(cur));

        } else if (*low.rbegin() > *up.begin()) {
            int l = *low.rbegin(), u = *up.begin();

            low.insert(u);
            low.erase(low.find(l));

            up.insert(l);
            up.erase(up.find(u));
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        double ans = *up.begin();
        if (low.size() == up.size()) {
            ans += *low.rbegin();
            ans /= 2;
        }
        return ans;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
/*
 * ok
 */
class MedianFinder {
private:
    multiset<int> small, large;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        small.insert(num);
        large.insert(*small.rbegin());
        small.erase(small.find(*small.rbegin()));
        if (small.size() + 1 < large.size()) {
            small.insert(*large.begin());
            large.erase(large.find(*large.begin()));
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        double ret = *large.begin();
        if (small.size() != large.size()) {
           ret += *large.begin();
        } else {
            ret += *small.rbegin();
        }
        return ret / 2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


