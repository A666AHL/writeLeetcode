// leetcode99. Recover Binary Search Tree
class Solution {
public:
	TreeNode *p1, *p2, *pre;
	void recoverTree(TreeNode* root) {
		traverse(root);
		int temp = p1->val;
		p1->val = p2->val;
		p2->val = temp;
	}
	void traverse(TreeNode* root) {
		if(root) {
			traverse(root->left);
			if(pre != nullptr && pre->val > root->val) {
				if(p1 == nullptr) p1 = pre;
				p2 = root;
			}
			pre = root;
			traverse(root->right);
		}
	}
};