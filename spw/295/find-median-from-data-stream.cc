#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

/**
 * Problem: Median is the middle value in an ordered integer list. If the
 *          size of the list is even, there is no middle value. So the
 *          median is the mean of the two middle value.
 * Solve: use two heap.
 * Tips: mind how to construct the min heap.
 */
struct Cmp{
    bool operator() (const int& a, const int&b) const {
        // > instead of <
        // inverse the default comparison
        return a > b;
    }
};
class MedianFinder {
public:
    priority_queue<int> leftHalf;
    priority_queue<int, vector<int>, Cmp> rightHalf;

    MedianFinder() {
        leftHalf.push(INT_MIN);
        rightHalf.push(INT_MAX);
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        if (num > rightHalf.top()) rightHalf.push(num);
        else leftHalf.push(num);

        if (leftHalf.size() > rightHalf.size()+1) {
            rightHalf.push(leftHalf.top());
            leftHalf.pop();
        } else if (rightHalf.size() > leftHalf.size()) {
            leftHalf.push(rightHalf.top());
            rightHalf.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (leftHalf.size() == rightHalf.size())
            return ((double)leftHalf.top()+rightHalf.top()) / 2;
        return leftHalf.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
//
int main()
{
    MedianFinder mf;
    mf.addNum(0);
    mf.addNum(0);
    cout << mf.findMedian();

    return 0;
}
