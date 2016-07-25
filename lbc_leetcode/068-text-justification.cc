/*
题目大意：
给一堆字符串，按照一定的格式将其格式化。

解题思路：
用贪心的方法，一行一行的处理就行。

遇到的问题：
1，一开始有个边界问题搞了好久才发现。if(len > maxWidth)
2，没看清题目条件中最后一行的特殊情况。

再次阅读：
感觉基本就是考察编程功底，贪心即可，没有什么算法可言。
但是之前的代码还是可以再改进一下的。
下面是一个DISCUSS中不错的代码，可以参考一下：
vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    for(int i = 0, k, l; i < words.size(); i += k) {
        for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
            l += words[i+k].size();
        }
        string tmp = words[i];
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";
            else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i+j+1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
    }
    return res;
}
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int left = 0, right = 0;
        while(left < words.size()){
            int len = words[left].size();
            right = left+1;
            while(len <= maxWidth && right < words.size()){
                len += 1+words[right].size();
                right++;
            }
            if(len > maxWidth){
                right--;
                len -= words[right].size()+1;
            }
            len -= right-left-1;

            string line = words[left];
            if(right-left == 1){
                string padding(maxWidth-len, ' ');
                line += padding;
            }else{
                if(right == words.size()){
                    for(int i = left+1; i < right; ++i){
                        line += " " + words[i];
                    }
                    string padding = string(maxWidth-len-(right-left-1), ' ');
                    line += padding;
                }
                else for(int i = left+1; i < right; ++i){
                    int whitespace = (maxWidth-len)/(right-left-1);
                    if(i-left <= (maxWidth-len)%(right-left-1)){
                        whitespace++;
                    }
                    string padding(whitespace, ' ');
                    line += padding;
                    line += words[i];
                }
            }
            ans.push_back(line);

            left = right;
        }
        return ans;
    }
};
/*
第二次做：
题目没有看清楚就做题了，有一句很重要的话：“For the last line of text, it should be left justified and no extra space is inserted between words.”
所以改了这部分，代码就对了。不过还是没有DISCUSS那么简洁，但是已经够用了。
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int index = 0;
        while (index < words.size()) {
            int totalLen = 0, num = 0, front = index;
            while (front < words.size() && (totalLen + num + words[front].size() <= maxWidth)) {
                totalLen += words[front++].size();
                num++;
            }

            string line;
            int blanks = maxWidth - totalLen;
            line.append(words[index]);
            num--;
            if (front == words.size()) {
                for (int i = index+1; i < front; ++i) {
                    line.append(" ");
                    line.append(words[i]);
                    blanks--;
                }
                line.append(string(blanks, ' '));
            } else {
                for (int i = index+1; i < front; ++i) {
                    int cur = blanks / num;
                    if (blanks % num) cur++;
                    blanks -= cur;
                    num--;

                    line.append(string(cur, ' '));
                    line.append(words[i]);
                }
                if (index+1 == front) line.append(string(blanks, ' '));
            }

            ans.push_back(line);
            index = front;
        }

        return ans;
    }
};
/*
 * this question is so boring that last line is different from others
 */
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int cur = 0;
        while (cur < words.size()) {
            int len = words[cur].size();
            int next = cur + 1;
            while (next < words.size() && len+1+words[next].size() <= maxWidth) {
                len += 1 + words[next].size();
                next++;
            }

            if (next == words.size()) {
                // hacking last line
                string now = words[cur];
                for (int i = cur+1; i < next; ++i) {
                    now += " ";
                    now += words[i];
                }
                now += string(maxWidth-now.size(), ' ');
                ans.push_back(now);
                return ans;
            }

            int num = next - cur;
            int space = maxWidth - len;
            string now = words[cur];
            for (int i = cur+1; i < next; ++i) {
                int curSpace = 1;
                curSpace += space / (next-i);
                if (space % (next-i)) curSpace++;
                space -= curSpace-1;
                now += string(curSpace, ' ');
                now += words[i];
            }
            if (next-1 == cur) now += string(maxWidth-len, ' '); // special case for only one word this line.
            ans.push_back(now);
            cur = next;
        }
        return ans; // actually ,we never get here.
    }
};
