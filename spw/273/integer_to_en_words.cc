#include <iostream>
#include <vector>
#include <string>

using namespace std;

string numberToWords(int num) {
    if (num == 0) return "Zero";
    string ones[] = {"", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
        "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen", "Twenty"};

    string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};

    string huns[] = {"", "Thousand", "Million", "Billion"};

    string ans;

    int i = 0;
    while (num) {
        string str;
        int now = num % 1000;
        num /= 1000;

        if (now >= 100) {
            str = ones[now/100] + " " + tens[10];
            now %= 100;
            if (now) str += " ";

        }

        if (now > 20) {
            str += tens[now/10];
            if (now % 10) str += " " + ones[now%10];

        } else {
            str += ones[now];

        }
        if (str != "" && i)  str += " ";
        if (str != "" || num == 0) str += huns[i];

        ans = str + (ans == "" ? "" : " ") + ans;
        ++i;

    }

    return ans;

}
int main() {
    int num;
    while (cin >> num) {
        cout << numberToWords(num) << endl;
    }

    return 0;
}
