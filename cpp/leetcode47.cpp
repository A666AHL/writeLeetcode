// ------------ April 6th ------------
// leetcode47.全排列
// 在leetcode46的基础上排序，跳过相同的数字即可
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    int len = nums.size();
    if(len == 0)
    {
        return res;
    }
    else if(len == 1)	// 递归结束 
    {
        temp.emplace_back(nums[0]);
        res.emplace_back(temp);
        return res;
    } else {
        sort(nums.begin(),nums.end());
		for(int i = 0; i < len; i++)
		{
			int  i_temp = 0;
			vector<int> temp(nums.begin(), nums.end());
			temp.erase(temp.begin() + i);
			for(int k = i+1; k < len; k++)
			{
				if(nums[i] == nums[k])
				{
					i_temp++;
				}
			}
			i+=i_temp;
			for(auto j : permuteUnique(temp)) {
				j.emplace(j.begin(), nums[i]);
				res.emplace_back(j);
			}
		}
    }
    return res;
}
int main()
{
	vector<int> nums {1,1,2};
	auto res = permuteUnique(nums);
	int len = res.size();
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < res[i].size(); j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 