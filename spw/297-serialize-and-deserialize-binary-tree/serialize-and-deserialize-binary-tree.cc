#include <iostream>
#include <string>
#include <queue>

/**
 * Problem: Serialization is the process of converting a data structure or
 *          object into a sequence of bits so that it can be stored in a file
 *          or memory buffer, or transmitted across a network connection link
 *          to be reconstructed later in the same or another computer environment.
 * Solve: level traversal
 * Tips: see comments below.
 */
using namespace std;
/**
 ** Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string to_string(int n) {
    string ans;
    while (n) {
        ans = (char)(n % 10 + '0') + ans;
        n /= 10;
    }

    return ans;
}

int stoi(string s) {
    int len = s.size();
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = ans * 10 + (s[i] - '0');
    }

    return ans;
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string ans = "[";

    queue<TreeNode*> q;
    if (root) {
        q.push(root);
        ans += to_string(root->val) + ",";
    }

    while (!q.empty()) {
        TreeNode *now = q.front();
        q.pop();

        if (now->left) {
            q.push(now->left);
            ans += to_string(now->left->val) + ",";
        } else {
            ans +=  "null,";
        }


        if (now->right) {
            q.push(now->right);
            ans += to_string(now->right->val) + ",";
        } else {
            ans += "null,";
        }
    }

    // remove the back null and ,
    int end = ans.size() - 1;
    while (ans[end] != '[' && (ans[end] < '0' || ans[end] > '9'))
        --end;

    return ans.substr(0, end+1) + ']';
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data == "[]") return NULL;

    int pos = 1, i = 1;
    queue<TreeNode*> q;
    while (data[i] != ',' && data[i] != ']') ++i;
    TreeNode *root = new TreeNode(stoi(data.substr(pos, i-pos)));
    q.push(root);

    int len = data.size();
    pos = ++i;
    while (pos < len) {
        while (data[i] != ',' && data[i] != ']') ++i;

        string tmp = data.substr(pos, i-pos);
        TreeNode *left = NULL;
        if (tmp != "null" && tmp != "") {
            left = new TreeNode(stoi(tmp));
            q.push(left);
        }

        pos = ++i;
        while (pos < len && data[i] != ',' && data[i] != ']') ++i;
        tmp = data.substr(pos, i-pos);
        TreeNode *right = NULL;
        if (tmp != "null" && tmp != "") {
            right = new TreeNode(stoi(tmp));
            q.push(right);
        }

        TreeNode *now = q.front();
        q.pop();
        now->left = left;
        now->right = right;

        pos = ++i;
    }

    return root;
}

int main()
{
    TreeNode *root = NULL;
    string s = serialize(root);
    root = deserialize(s);

    return 0;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "[";

        queue<TreeNode *> q;
        if (root) q.push(root);


        while (!q.empty()) {
            queue<TreeNode*> next;
            bool allNull = true;
            while (!q.empty()) {
                TreeNode *now = q.front();
                q.pop();

                if (ans == "[") {
                    ans += to_string(now->val);
                } else if (now != NULL) {
                    ans += "," + to_string(now->val);
                } else {
                    ans += ",null";
                }

                if (now) {
                    next.push(now->left);
                    next.push(now->right);
                    if (now->left || now->right) allNull = false;
                }
            }
            // skip the bottom null
            if (!allNull) q = next;
        }

        ans += "]";

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;

        int i = 1, n = data.size() - 1, start = i;
        while (i < n && data[i] != ',') ++i;
        string now = data.substr(start, i-start);

        // get the root first
        TreeNode *root = new TreeNode(stoi(now));
        queue<TreeNode*> q;
        q.push(root);


        while (i < n) {
            start = ++i;
            while (i < n && data[i] != ',') ++i;
            string left = data.substr(start, i-start);
            if (left != "null") {
                q.front()->left = new TreeNode(stoi(left));
                q.push(q.front()->left);
            }

            start = ++i;
            while (i < n && data[i] != ',') ++i;
            string right = data.substr(start, i-start);
            if (right != "null") {
                q.front()->right = new TreeNode(stoi(right));
                q.push(q.front()->right);
            }

            q.pop();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
