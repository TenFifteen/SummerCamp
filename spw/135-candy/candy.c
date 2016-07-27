#include <stdio.h>
#include <stdlib.h>
#define N 100
#define max(a, b) ((a) > (b) ? (a) : (b))

/**
 * Problem: Each child must have at least one candy.
 *          Children with a higher rating get more candies than their neighbors.
 * Solve: use an array
 * Tips: 1. I needn't use only O(1) space.
 *       2. if two children are neighbors with the same rationgs, they needn't have the same candies.
 *          That is if ratings[i] = ratings[i+1] and candy[i] = 5, candy [i+1] can be 1
 *       3. watch out the assignment of range index
 */
int candy(int* ratings, int ratingsSize) {
	if (ratingsSize < 2) return ratingsSize;
	int *candies = malloc(sizeof(int) * ratingsSize);

	int i;
	for (i = 0; i < ratingsSize; ++i) candies[i] = 1;

	// assignment from index = 1...n-1
	for (i = 1; i < ratingsSize; ++i) {
		if (ratings[i] > ratings[i-1]) {
			candies[i] = candies[i-1] + 1;
		}
	}

	// assignment from index = n-2...0
	for (i = ratingsSize-1; i > 0; --i) {
		if (ratings[i-1] > ratings[i]) {
			candies[i-1] = max(candies[i-1], candies[i]+1);
		}
	}

	int sum = 0;
	for (i = 0; i < ratingsSize; ++i) sum += candies[i];
	free(candies);

	return sum;
}

int main()
{
	int n;
	int arr[N];
	while (~scanf("%d", &n)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		int sum = candy(arr, n);
		printf("The minimum candies are %d\n", sum);
	}

	return 0;
}

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) return n;

        vector<int> candy(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
        }

        int ans = candy[n-1];
        for (int i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1])
                candy[i] = max(candy[i], candy[i+1]+1);
            ans += candy[i];
        }

        return ans;
    }
};
