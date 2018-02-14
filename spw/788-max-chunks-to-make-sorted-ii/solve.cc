/**
 * Problem: Given an array arr of integers (not necessarily distinct), we
 *          split the array into some number of "chunks" (partitions), and
 *          individually sort each chunk.  After concatenating them, the result
 *          equals the sorted array.
 *          What is the most number of chunks we could have made?
 * Solve: sort and dict
 * Tips: when ++ still have change to equal zero
 */
class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
            vector<int> sortedArr(arr);
            sort(sortedArr.begin(), sortedArr.end());

            unordered_map<int, int> cnt;
            int n = arr.size();
            int res = 0;
            for (int i = 0; i < n; ++i) {
                cnt[arr[i]]++;
                cnt[sortedArr[i]]--;
                /*
                   cout << "+" << arr[i] << endl;
                   cout << "-" << sortedArr[i] << endl;
                   cout << "dict size: " << cnt.size() << endl;
                   */
                if (cnt[sortedArr[i]] == 0)
                    cnt.erase(sortedArr[i]);
                if (cnt[arr[i]] == 0)
                    cnt.erase(arr[i]);
                if (cnt.empty())
                    ++res;
            }

            return res;
        }
};
