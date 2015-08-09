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
