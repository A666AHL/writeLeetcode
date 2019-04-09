class Solution {
public:
	int res = 0;
	void fun(TreeNode* node, int len, int* path)
	{
		if(node == NULL)
			return;
		path[len] = node ->val;
		len++;
		if(node -> left == NULL && node -> right == NULL)
		{
			int temp = path[0];
			for(int i = 1; i < len; i++)
			{
				temp <<= 1;
				temp += path[i];
				temp %= 1000000007;
			}
			res += temp;
			res %= 1000000007;
		}
		fun(node -> left, len, path);
		fun(node -> right, len, path);
	}

	int sumRootToLeaf(TreeNode* root)
	{
		int len = 0;
		int path[10000];
		fun(root, len, path);
		return res;
	}
};
