/**
 * Problem: Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * Solve: use a sum array.
 * Tips: no
 */
class NumArray {
    vector<long long> sumArr;
    public:
    NumArray(vector<int> &nums) {
        sumArr.resize(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sumArr[i+1] = sumArr[i] + nums[i];

        }

    }

    int sumRange(int i, int j) {
        return sumArr[j+1] - sumArr[i];

    }

};

class NumArray {
    vector<int> partialSum;
public:
    NumArray(vector<int> &nums) {
        partialSum.resize(nums.size()+1);
        partialSum[0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            partialSum[i] = partialSum[i-1] + nums[i-1];
        }
    }

    int sumRange(int i, int j) {
        return partialSum[j+1]-partialSum[i];
    }
};

