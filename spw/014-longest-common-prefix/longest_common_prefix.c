
/**
 *	find the minimum length of the strs
 *	then we can solve it use the simplest ways
 */
char* longestCommonPrefix(char** strs, int strsSize) {

	if (strsSize == 0) return "";

	int i, j, min_len = strlen(strs[0]);
	for (i = 1; i < strsSize; ++i) {
		int this_len = strlen(strs[i]);
		if (min_len > this_len) min_len = this_len;
	}

	if (min_len == 0) return "";

	char *pre = malloc(sizeof(char) * (min_len+1));
	for (i = 0; i < min_len; ++i) {
		char this_char = strs[0][i];
		pre[i] = this_char;

		for (j = 1; j < strsSize; ++j) {
			if (strs[j][i] != this_char) {
				pre[i] = '\0';
				return pre;
			}
		}
	}

	pre[i] = '\0';
	return pre;
}
/**
 * 用第一个字符串作为标杆， 一列一列的，与第一行对比，发下不同的字符，则将前面相同的前缀
 * 返回。
 * 注意，空字符串数组的时候。
 */
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string ans;
            if (strs.size() == 0) return ans;

            int n = strs.size(),  len = strs[0].size();

            for (int pos = 0; pos < len; ++pos) {
                for (int i = 1; i < n; ++i) {
                    if (pos >= strs[i].size() || strs[i][pos] != strs[0][pos])
                        return strs[0].substr(0, pos);
                }
            }
            return strs[0];

        }

};
