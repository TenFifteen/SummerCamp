/*
ID: libench1
PROG: prefix
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");

    vector<string> prefix;
    string input;
    while (true) {
        fin >> input;
        if (input == ".") {
            break;
        }

        prefix.push_back(input);
    }

    string word;
    while (fin >> input) {
        word.append(input);
    }

    vector<bool> ans(word.size(), false);
    for (int i = 0;i < word.size(); ++i) {
        for (int j = 0; j < prefix.size(); ++j) {
            if (prefix[j].size() > i+1) continue;
            if (prefix[j] == word.substr(i-prefix[j].size()+1, prefix[j].size()) && (i+1 == prefix[j].size() || ans[i-prefix[j].size()])) {
                ans[i] = true;
                break;
            }
        }
    }

    int len = 0;
    for (int i = word.size()-1; i >= 0; --i) {
        if (ans[i]) {
            len = i+1;
            break;
        }
    }

    fout << len << endl;

    return 0;
}
