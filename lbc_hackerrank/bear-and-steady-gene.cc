#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

const int maxn = 6000004;
char str[maxn];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    cin >> str;
    unordered_map<char, int> um;
    for (int i = 0; i < n; ++i) {
        um[str[i]]++;
    }
    
    string tmp;
    for (auto u : um) {
        if (u.second <= n/4) tmp.push_back(u.first);
    }
    for (auto ch : tmp) {
        um.erase(ch);
    }
    for (auto &u : um) {
        u.second -= n/4;
    }
    
    int left = 0, right = 0, ans = INT_MAX, total = 0;
    unordered_map<char, int> count;
    if (um.size() != 0) while (right < n) { // um.size() != 0 for nothing for be find.
        while (right < n && total < um.size()) {
            if (um.find(str[right]) != um.end()) {
                count[str[right]]++;
                if (count[str[right]] == um[str[right]]) total++;
            }
            right++;
        }
        
        while (total == um.size()) {
            if (um.find(str[left]) != um.end()) {
                count[str[left]]--;
                if (count[str[left]] == um[str[left]]-1) total--;
            }
            left++;
        }
        ans = min(ans, right-left+1);
    } else {
        ans = 0;
    }
    cout << ans << endl;
    
    return 0;
}
