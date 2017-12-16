#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1) return s;
    string *rows = new string[numRows];

    int n = s.size();
    int row = 0;
    int pre = -1;
    /*
     * this segment can also be:
     * if (row == 0)
     *      step = 1;
     *  else if (row == nRows - 1)
     *      step = -1;
     *  row += step;
     */
    for (int i = 0; i < n; ++i) {
        rows[row] += s[i];

        if (row > pre) {
            pre = row;
            row++;
        } else {
            pre = row;
            --row;
        }

        if (row < 0) {
            row = 1;
        } else if (row == numRows){
            row = numRows - 2;
        }
    }

    s = "";
    for (int i = 0; i < numRows; ++i) s += rows[i];
    delete [] rows;

    return s;
}


int main()
{
    string s;
    while (cin >> s) {
        cout << "The zigzag of string " << s << " is " << convert(s, 3) << endl;
    }

    return 0;
}

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows <= 1) return s;

            int n = s.size();
            string result(s);

            int i, j, pos = 0;
            int step = 2 * numRows - 2;
            bool flag = 0;
            for (i = 0; i < numRows; ++i) {
                if (i == 0 || i == numRows-1) {
                    for (j = i; j < n; j += step) {
                        result[pos++] = s[j];

                    }

                } else {
                    int right_step = 2 * i;
                    int left_step = step - right_step;
                    j = i;
                    flag = 0;
                    while (j < n) {
                        result[pos++] = s[j];

                        j += flag ? right_step : left_step;
                        flag = !flag;

                    }

                }

            }


            return result;

        }

};
