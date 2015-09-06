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
