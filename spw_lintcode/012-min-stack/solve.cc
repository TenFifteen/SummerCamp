/**
 * Problem: Implement a stack with min() function, which will return the smallest number in the stack.
 *          It should support push, pop and min operation all in O(1) cost.
 * Solve: use three stack. to minimum the usage of the aside stack when there are too many duplicates.
 * Tips: no
 */
class MinStack {
    private:
        stack<int> data;

        stack<int> minEle;
        stack<int> index;
    public:
        MinStack() {
            // do initialization if necessary
        }

        void push(int number) {
            data.push(number);
            if (minEle.empty() || minEle.top() > number) {
                minEle.push(number);
                index.push(data.size());
            }
        }

        int pop() {
            int top = data.top();
            if (top == minEle.top() && data.size() == index.top()) {
                index.pop();
                minEle.pop();
            }
            data.pop();

            return top;
        }

        int min() {
            if (!minEle.empty()) return minEle.top();

            return 0;
        }
};

