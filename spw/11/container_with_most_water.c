#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/**
 * the simplest way : O(n^2)
 */
int maxArea(int* height, int heightSize)
{
	//int *dp = malloc(sizeof(int)  * (heightSize + 1));
	if (heightSize == 0  || heightSize == 1) return 0;

	int i, j, result = 0;
	for (i = 0; i < heightSize; ++i) {
		int capacity = 0, max_capacity = 0;
		for (j = i+1; j < heightSize; ++j) {
			capacity = (height[j] > height[i] ? height[i] : height[j]) * (j - i);
			max_capacity = max_capacity > capacity ? max_capacity : capacity;
		}
		result = result < max_capacity ? max_capacity : result;
	}

	return result;
}

/**
 * Firt we consider the widest container, if any one between it want to hold more water,
 * the min height of the container must be higher than 
 * 其实就是寻找一个单调性的方法，capacity = w * h, 开始我们让w最大，然后逐渐减小它，那么想要
 * 得到更大的capacity，我们必须找到更大的h。也就是逐渐提升短板，左右一下一下来。高的肯定不会被代替,
 * 除非它也成为短板。
 */
int max_area(int* height, int heightSize)
{
	int s = 0, e = heightSize - 1;
	int water = 0;
	while (e > s) {
		int h = min(height[s], height[e]);	
		water = max(water, h * (e - s));	

		while (height[s] <= h) ++s;
		while (height[e] <= h) --e;
	}

	return water;
}

int main()
{
	int n, board[1000];
	while (~scanf("%d", &n)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &board[i]);
		}

		printf("The max capacity of the container is %d and %d\n", maxArea(board, n), max_area(board, n));
	}

	return 0;
}
