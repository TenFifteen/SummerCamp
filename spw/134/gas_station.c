/*
 * Problem: There are N gas station along a circular route, where the amount of gas at station i is gas[i];
 *          You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i
 *          to its next station (i+1). You begin the journey with an emtpy tank at one of the gas station.
 *          Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * Solve: 1. if car start A and can reach B(B is the first station that can't be reached from A), then Any station
 *        between A and B can't reach B.
 *        2. if the total number of gas is bigger than the total number of cost, there must be a solution
 * Tips: copy
 */
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
	int sum = 0;

	int i, hold = 0, start = 0;
	for (i = 0; i < costSize; ++i) {
		int now = gas[i] - cost[i];
		sum += now;
		hold += now;
		if (hold < 0) {
			hold = 0;
			start = i + 1;
		}
	}
	if (sum < 0) {
		return -1;
	} else {
		return start;
	}
}
/**
 * Proof to the first point: say there is a point C between A and B -- that is A can reach C but cannot reach B. Since A cannot reach B, the gas collected between A and B is short of the cost. Starting from A, at the time when the car reaches C, it brings in gas >= 0, and the car still cannot reach B. Thus if the car just starts from C, it definitely cannot reach B.
 *
 * Proof for the second point:
 *
 * If there is only one gas station, it’s true.
 * If there are two gas stations a and b, and gas(a) cannot afford cost(a), i.e., gas(a) < cost(a), then gas(b) must be greater than cost(b), i.e., gas(b) > cost(b), since gas(a) + gas(b) > cost(a) + cost(b); so there must be a way too.
 * If there are three gas stations a, b, and c, where gas(a) < cost(a), i.e., we cannot travel from a to b directly, then:
 * either if gas(b) < cost(b), i.e., we cannot travel from b to c directly, then cost(c) > cost(c), so we can start at c and travel to a; since gas(b) < cost(b), gas(c) + gas(a) must be greater than cost(c) + cost(a), so we can continue traveling from a to b. Key Point: this can be considered as there is one station at c’ with gas(c’) = gas(c) + gas(a) and the cost from c’ to b is cost(c’) = cost(c) + cost(a), and the problem reduces to a problem with two stations. This in turn becomes the problem with two stations above.
 * or if gas(b) >= cost(b), we can travel from b to c directly. Similar to the case above, this problem can reduce to a problem with two stations b’ and a, where gas(b’) = gas(b) + gas(c) and cost(b’) = cost(b) + cost(c). Since gas(a) < cost(a), gas(b’) must be greater than cost(b’), so it’s solved too.
 * For problems with more stations, we can reduce them in a similar way. In fact, as seen above for the example of three stations, the problem of two stations can also reduce to the initial problem with one station.
 */
