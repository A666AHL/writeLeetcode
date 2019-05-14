// leetcode98.Validate Binary Search Tree
class Solution {
public:
    vector<int> vTree;
    void traverse(TreeNode* root) {
        if(root) {
            traverse(root->left);
            vTree.emplace_back(root->val);
            traverse(root->right);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) 
            return true;
        traverse(root);
        int len = vTree.size();
        int temp = vTree[0];
        for(int i = 1; i < len; i++) // 如果vTree 是严格递增的则为搜索二叉树
        {
            if(vTree[i] > temp) {
                temp = vTree[i];
            } else{
                return false;
            }
        }
        return true;
    }
};