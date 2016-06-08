/*
题目大意：
给定一个数据类型，实现其迭代器。

解题思路：
stack，见代码。

遇到的问题：
没有太大问题。
不过C++中声明了返回值，但是不写返回值竟然可以编译通过并运行，也是一件
非常奇葩的事情啊。
*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<const vector<NestedInteger> *> arr;
    stack<int> index;
    
    void reset() {
        while (true) {
            if (arr.size() == 0) break;
            if (arr.top()->size() == index.top()) {
                arr.pop(); index.pop();
                if (index.size() != 0) index.top()++;
            } else if (!(*arr.top())[index.top()].isInteger()) {
                arr.push(&(*arr.top())[index.top()].getList());
                index.push(0);
            } else {
                break;
            }
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        arr.push(&nestedList);
        index.push(0);
        reset();
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int ret = (*arr.top())[index.top()].getInteger();
        index.top()++;
        reset();
        return ret;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        return arr.size() != 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
