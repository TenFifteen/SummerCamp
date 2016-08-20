/*
题目大意：
问一个字符串是否是一个二叉树的先序遍历的序列化的结果。

解题思路：
只是一个普通的二叉树，所以不需要比较各节点直接的大小，只是判断是否是一棵完整的二叉树即可。
我就是利用的当前有多少个空余的link来计算是否合理。如果当前是一个#，则说明link减一；
如果当前是一个数字，表示link加一

遇到的问题：
没有太大问题。

再次阅读：
看了一下DISCUSS，感觉这种解法已经算是不错的解法了。
*/
class Solution {
private:
    vector<string> split(const string &str) {
        stringstream ss(str);
        string cur;
        vector<string> ans;
        while (getline(ss, cur, ',')) {
            ans.push_back(cur);
        }
        return ans;
    }
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes = split(preorder);
        if (nodes.size() == 0) return false;
        if (nodes.size() > 1 && nodes[0] == "#") return false;
        int total = 1;
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i] == "#") {
                total--;
                if (total < 0) return false;
            } else {
                if (total == 0) return false;
                total++;
            }
        }

        return total == 0;
    }
};
/*
第二次做：
没有太大问题。
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int need = 1, index = 0;
        while (index < preorder.size() && need > 0) {
            if (preorder[index] == '#') {
                need--;
                index += 2;
            } else {
                int end = index+1;
                while (end < preorder.size() && preorder[end] != ',') end++;
                need++;
                index = end+1;
            }
        }

        return need == 0 && index >= preorder.size();
    }
};
/*
 * ok
 */
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int total = 1;
        int index = 0;
        stringstream ss(preorder);
        string now;
        bool finish = false;
        while (getline(ss, now, ',')) {
            if (now[0] == '#') {
                total--;
                if (total == 0) {
                    finish = true;
                }
            } else {
                if (finish) return false;
                total++;
            }
        }
        return !total;
    }
};
