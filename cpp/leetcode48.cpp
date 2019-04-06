// --------- April 6th ---------
// leetcode48.旋转图象
// 分步进行,先进行第一行与第一列交换
// 第二行与第二列交换，注意此时不包括上一步的第一行与第一列
// …… 遍历完全
// 再对每一行逆转
void rotate(vector<vector<int>>& matrix) {
	int len = matrix.size();
	if(len == 0 || len == 1)
	{
		return;
	}
	else{
		for(int i = 0; i < len; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
		// 每一行逆转
		for(int i = 0; i < len; i++)
		{   
			for(int j = 0; j < len/2; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][len-1-j];
				matrix[i][len-1-j] = temp;
			}
		}
	}
}