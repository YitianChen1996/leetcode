#include "base.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    vector<TreeNode *> path; // cursor is always at the top of the path, and it is printed
                             // path is empty means cursor reach the end

    TreeNode *getCursor() { return path.empty() ? NULL : path.back(); }
    
public:
    BSTIterator(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        TreeNode *p = root;

        //init to the first cursor
        while (p->left != NULL) {
            path.push_back(p);
            p = p->left;
        }
        path.push_back(p);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!path.size() == 1 && getCursor()->right == NULL);
    }

    /** @return the next smallest number */
    int next() {
        if (!hasNext()) {
            cout << "[ERROR], this is the end of the tree" << endl;
            return -1;
        }
        int ret;
        if (getCursor()->right == NULL) {
            path.pop_back();
            ret = getCursor()->val;
        } else { // cursor has right. Go right one time, and go left until you can not go left anymore.
            TreeNode *tempRight = getCursor()->right;
            path.pop_back();
            path.push_back(tempRight);
            while (getCursor()->left != NULL) {
                path.push_back(getCursor()->left);
            }
            ret = getCursor()->val;
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

 int main() {
    return 0;
 }
