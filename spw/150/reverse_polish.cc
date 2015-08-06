/**
 * Problem: Evaluate the value of an arithmetric expression in Reverse Polish Notation.
 * Solve: use stack
 * Tips: use branch bravely.
 */
int evalRPN(vector<string>& tokens) {
	stack<int> ops;
	int op1, op2;
	for (int i = 0; i < tokens.size(); ++i) {
		if (tokens[i] == "+") {
			op1 = ops.top(); ops.pop();
			op2 = ops.top(); ops.pop();
			ops.push(op1+op2);
		} else if (tokens[i] == "-") {
			op1 = ops.top(); ops.pop();
			op2 = ops.top(); ops.pop();
			ops.push(op2-op1);
		} else if (tokens[i] == "*") {
			op1 = ops.top(); ops.pop();
			op2 = ops.top(); ops.pop();
			ops.push(op2*op1);
		} else if (tokens[i] == "/") {
			op1 = ops.top(); ops.pop();
			op2 = ops.top(); ops.pop();
			ops.push(op2/op1);
		} else {
			ops.push(stoi(tokens[i]));
		}
	}

	return ops.top();
}
