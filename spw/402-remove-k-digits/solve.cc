class Solution {
public:
    string removeKdigits(string num, int k) {
        while (k != 0 && k < num.size()) {
            int i = 0;
            while (i + 1 < num.size() && num[i+1] == num[i]) ++i;

            int l = INT_MIN, r = -1, now = num[i]-'0';
            for (; i < num.size(); ++i) {
                r = i == num.size()-1 ? -1 : num[i+1]-'0';
                if (now >= l && now >= r) {
                    num = num.substr(0, i) + num.substr(i+1);
                    break;
                }
                l = now;
                now = r;
            }

            i = 0;
            while (i < num.size() && num[i] == '0') ++i;
            if (i == num.size()) num = "";
            else if (i != 0) num = num.substr(i);
            --k;
        }

        if (k >= num.size()) return "0";
        return num;
    }
};
