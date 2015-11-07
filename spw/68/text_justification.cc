#include <vector>
#include <iostream>

using namespace std;

/**
 * Problem: text justification.
 * Solve: 1. Use the least interval: one space after one word plus the next word size
 *           to judge if we should construct a line.
 *        2. When we construct a line, we should carefully calculate the spaces after
 *           each word.
 *           If we can't balanced the spaces after each word, we should assign extra sapces
 *           on the left firstly.
 * Tips:  1. If there is only one word in a line, then we have only one space slot, otherwise
 *           we have count of slots which is word count minus one.
 *        2. Use mod and divide to assign the spaces.
 *        3. The last line, all the space slots but the last one have only one space.
 *
 */
vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> ans;
    int word_count = 0, sum_len = 0, last_index = 0;
    for (int i = 0; i < words.size(); ++i) {
        sum_len += words[i].size();
        word_count++;

        if (i == words.size()-1 || sum_len+word_count+words[i+1].size() > maxWidth) {
            string line;
            int total_spaces_len = maxWidth - sum_len;
            if (i == words.size()-1) {
                for (int j = last_index; j < i; ++j) {
                    line += (words[j]+" ");
                }
                string space_str(total_spaces_len-(word_count-1), ' ');
                line += (words[i]+space_str);
            } else {
                int space_count = word_count - 1;
                if (word_count == 1) space_count = word_count;
                int space = total_spaces_len / space_count;
                int more = total_spaces_len % space_count;
                for (int j = last_index; j <= i; ++j) {
                    int s = space;
                    if (more-- > 0) {
                        s += 1;
                    }
                    string spaces_str(s, ' ');
                    line += words[j];
                    if (word_count == 1 || j < i) line += spaces_str;
                }
            }
            ans.push_back(line);
            last_index = i + 1;
            word_count = 0;
            sum_len = 0;
        }
    }

    return ans;
}

int main()
{

}
