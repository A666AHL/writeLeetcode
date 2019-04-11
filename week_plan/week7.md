## week7_question

leetcode46~50

## week7_exercise

leetcode周赛131

## week7_shared

- leetcode5017

```c++
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
```

- 用栈实现遍历二叉树，运行原理与递归遍历一致，代码没有贴出，感兴趣的同学可以尝试实现一下