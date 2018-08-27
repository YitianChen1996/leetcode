#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    void preorderTraverse(TreeNode *node, vector<string> &res) {
        if (node == nullptr) {
            res.push_back("n");
        } else {
            res.push_back(to_string(node->val));
            preorderTraverse(node->left, res);
            preorderTraverse(node->right, res);
        }
    }

    void vectorToString(const vector<string> &vec, string &ret) {
        int i;
        for (i = 0; i <= (int) vec.size() - 2; i++) {
            ret += vec[i];
            ret += ",";
        }
        ret += vec[i];
    }

    void stringToVector(const string &s, vector<string> &ret) {
        ret.clear();
        if (s.empty()) { return; }
        int beginIndex = 0, endIndex = 1;
        while (true) {
            endIndex = beginIndex + 1;
            while (endIndex < s.length() && s[endIndex] != ',') {
                endIndex++;
            }
            ret.push_back(s.substring(beginIndex, endIndex - beginIndex));
            if (endIndex >= s.length()) { break; }
            beginIndex = endIndex + 1;
        }
    }

    TreeNode* constructTreeByVector(const vector<string> &vec, int leftBound, int rightBound) {
        if (vec[leftBound] == "n") { return nullptr; }
        TreeNode *root = new TreeNode(stoi(vec[leftBound], nullptr, 10));
        int nullNum = 0, valNum = 0;
        int leftSubTree_leftBound, leftSubTree_rightBound, rightSubTree_leftBound, rightSubTree_rightBound;
        leftSubTree_leftBound = leftBound + 1;
        rightSubTree_rightBound = rightBound;
        int p = leftBound;
        while (nullNum != valNum + 1) {
            p++;
            if (vec[p] == "n") {
                nullNum++;
            } else {
                valNum++;
            }
        }
        leftSubTree_rightBound = p;
        rightSubTree_leftBound = p + 1;
        root->left = constructTreeByVector(vec, leftSubTree_leftBound, leftSubTree_rightBound);
        root->right = constructTreeByVector(vec, rightSubTree_leftBound, rightSubTree_rightBound);
        return root;
    }
 
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        vector<string> res;
        preorderTraverse(root, res);
        vectorToString(res, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec;
        vec = stringToVector(data, vec);
        return constructTreeByVector(vec, 0, vec.size() - 1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    
}
