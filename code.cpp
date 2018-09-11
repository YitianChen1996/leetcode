#include "base.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<int> ans;

	void rightFirstTraverse(TreeNode *node, int layer) {
		if (node == NULL) { return; }
		if (layer + 1 > ans.size()) {
			ans.push_back(node->val);
		}
		node->rightFirstTraverse(node->right, layer + 1);
		node->rightFirstTraverse(node->left, layer + 1);
	}

public:
    vector<int> rightSideView(TreeNode* root) {
		rightFirstTraverse(root, 0);
		return ans;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<string> ans;
	ans = solution->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
