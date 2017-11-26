#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTreeByVector(const vector<int> &v, int index) {
    TreeNode *new_node;
    new_node = new TreeNode(v[index]);
    if (2 * index >= v.size() || v[2 * index] == -1) {
        new_node->left = nullptr;
    } else {
        new_node->left = buildTreeByVector(v, 2 * index);
    }
    if (2 * index + 1 >= v.size() || v[2 * index + 1] == -1) {
        new_node->right = nullptr;
    } else {
        new_node->right = buildTreeByVector(v, 2 * index + 1);
    }
    return new_node;
}

int main() {
    vector<int> v;
    v.push_back(-2);
    while (true) {
        int n;
        cin >> n;
        if (n == -2) {
            break;
        }
        v.push_back(n);
    }
    TreeNode *root;
    root = buildTreeByVector(v, 1);
    return 0;
}