/*
ID: libench1
PROG: namenum
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, string> mm;

void find_names(vector<string> &ans, string num, string cur, unordered_set<string> &dict) {
    if (num == "") {
        if (dict.find(cur) != dict.end()) {
            ans.push_back(cur);
        }
        return;
    }

    for (auto ch : mm[num[0]]) {
        cur.push_back(ch);
        find_names(ans, num.substr(1, num.size()-1), cur, dict);
        cur.pop_back();
    }
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dictfile ("dict.txt");

    mm['2'] = "ABC";
    mm['3'] = "DEF";
    mm['4'] = "GHI";
    mm['5'] = "JKL";
    mm['6'] = "MNO";
    mm['7'] = "PRS";
    mm['8'] = "TUV";
    mm['9'] = "WXY";

    unordered_set<string> dict;
    string tmp;
    while (dictfile >> tmp) {
        dict.insert(tmp);
    }


    string num;
    while(fin >> num) {
        vector<string> ans;
        find_names(ans, num, "", dict);

        for (int i = 0; i < ans.size(); ++i) {
            fout << ans[i] << endl;
        }
        if (ans.size() == 0) {
            fout << "NONE" << endl;
        }
    }

    return 0;
}
