/**
 * Problem: given an unsorted array, find the maximum difference between the successive
 *          elements in sorted form.
 * Solve: sort and find.
 * Tips: no
 */
#define max(a, b) ((a) > (b) ? (a) : (b))
int swap(int v[], int a, int b) {
    if (v[a] == v[b]) return;
    v[a] = v[a] ^ v[b];
    v[b] = v[a] ^ v[b];
    v[a] = v[a] ^ v[b];
}
void mysort(int v[], int left, int right) {
    if (left >= right) return;

    swap(v, left, (left+right)/2);
    int i, last = left;
    for (i = left+1; i <= right; ++i){
        if (v[i] < v[left]) {
            swap(v, i, ++last);
        }
    }

    swap(v, left, last);
    mysort(v, left, last-1);
    mysort(v, last+1, right);
}
int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    mysort(nums, 0, numsSize-1);
    int i;
    int max_diff = 0;
    for (i = 1; i < numsSize; ++i) {
        max_diff = max(max_diff, nums[i]-nums[i-1]);
    }

    return max_diff;
}
