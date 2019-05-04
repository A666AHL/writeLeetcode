// leetcode95.Unique Binary Search Trees II
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generate(int start, int end)
    {
        vector<TreeNode*> res;
        if(start > end)
        {
            res.emplace_back(nullptr);
            return res;
        }
        for(int i = start; i <= end; i++)
        {
            // 得到root=i的右子树
            vector<TreeNode*> left_tree = generate(start, i-1);
            // 得到root=i的左子树
            vector<TreeNode*> right_tree = generate(i+1, end);
            for(int j = 0; j < left_tree.size(); j++)
            {
                for(int k = 0; k < right_tree.size(); k++)
                {
                    TreeNode* node = new TreeNode(i); //生成节点node=i
                    res.emplace_back(node);
                    node->left = left_tree[j];
                    node->right = right_tree[k];
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return generate(1, n);
    }
};