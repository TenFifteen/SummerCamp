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
