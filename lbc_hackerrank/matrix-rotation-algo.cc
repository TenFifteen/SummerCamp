#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m, n, r;
    cin >> m >> n >> r;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    int left = 0, right = n-1;
    int top = 0, bot = m-1;
    while (left <= right && top <= bot) {
        int cnt = (right-left+1)*2 + (bot-top-1)*2;
        int total = r % cnt;
        while (total--) {
            int tmp = matrix[top][left];
            for (int i = left+1; i <= right; ++i) matrix[top][i-1] = matrix[top][i];
            for (int i = top+1; i <= bot; ++i) matrix[i-1][right] = matrix[i][right];
            for (int i = right-1; i >= left; --i) matrix[bot][i+1] = matrix[bot][i];
            for (int i = bot-1; i >= top; --i) matrix[i+1][left] = matrix[i][left];
            matrix[top+1][left] = tmp;
        }
        left++;
        right--;
        top++;
        bot--;
    }
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j];
            if (j != n-1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
