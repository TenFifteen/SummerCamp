/**
 * Problem: Design a stack that supports push, pop, top and retriveving the
 *          minimum element in constan time.
 * Solve: use tow stack, one to sotre element and another to store the minimum
 *        elements form the bottome to the top.
 * Tips: no
 */
stack<int> s;
stack<int> mins;

void push(int x) {
	s.push(x);
	if (!mins.empty()) {
		mins.push(min(mins.top(), x));
	} else {
		mins.push(x);
	}
}

void pop() {
	s.pop();
	mins.pop();
}

int top() {
	return s.top();
}

int getMin() {
	return mins.top();
}

class MinStack {
    stack<int> data;
    stack<pair<int, int>> minEle;
public:
    MinStack() {

    }

    void push(int x) {
        data.push(x);
        if (minEle.empty() || minEle.top().first > x) {
            minEle.push(make_pair(x, 1));
        } else if (minEle.top().first == x) {
            minEle.top().second++;
        }
    }

    void pop() {
        if (minEle.top().first == data.top()) {
            minEle.top().second--;
// need to pop
            if (minEle.top().second == 0)
                minEle.pop();
        }
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minEle.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
