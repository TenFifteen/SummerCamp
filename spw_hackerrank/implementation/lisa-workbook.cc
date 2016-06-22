/**
 * Problem: Lisa just got a new math workbook. A workbook contains
 *          exercise problems, grouped into chapters.
 *          There are  n chapters in Lisa's workbook, numbered from  1 to n.
 *          The i-th chapter has  problems, numbered from 1 to ti.
 *          Each page can hold up to  problems. There are no empty pages or
 *          unnecessary spaces, so only the last page of a chapter may contain fewer than  problems.
 *          Each new chapter starts on a new page, so a page will never contain
 *          problems from more than one chapter.
 *          The page number indexing starts at .
 *          Lisa believes a problem to be special if its index (within a chapter)
 *          is the same as the page number where it's located. Given the details
 *          for Lisa's workbook, can you count its number of special problems?
 * Solve: just keep two variable: pageNo and problemNo and simulate.
 * Tips
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ans = 0, page = 1;
    for (int i = 0; i < n; ++i) {
        int pno = 1, t;
        cin >> t;
        while (t >= k) {
            if (pno <= page && page <= pno+k-1) ans++;

            pno += k;
            t -= k;
            page ++;
        }

        if (t > 0) {
            if (pno <= page && page <= pno+t-1) ans++;
            page++;
        }
    }
    cout << ans << endl;

    return 0;
}

