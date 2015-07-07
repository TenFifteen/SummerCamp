#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * find from the discuss board of the leetcode
 * use a dictionary to hold the map from num to index, then we can find in O(1) time
 * note: each num int the vector nums must occour once
 */
vector<int> twoSum(vector<int>& nums, int target) 
{
	unordered_map<int, int> num_index;
	vector<int> result;

	for (int i = 0; i < nums.size(); ++i) {
		int num_to_find = target - nums[i];

		if (num_index.find(num_to_find) != num_index.end()) {
			result.push_back(num_index[num_to_find] + 1);
			result.push_back(i + 1);
			return result;
		}
		num_index[nums[i]] = i;
	}
}


int main()
{
	int n, target, tmp;
	vector<int> array(1000);
	while (~scanf("%d %d", &n, &target)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			array[i] = tmp;
		}
		vector<int> result = twoSum(array, target);
		printf("index1=%d, index2=%d\n", result[0], result[1]);
	}

	return 0;
}
