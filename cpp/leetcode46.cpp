// leetcode46.全排列
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> permute(vector<int>& nums) {
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
        int k = 0;
        for(auto i : nums)
        {
            vector<int> temp(nums.begin(), nums.end());
            temp.erase(temp.begin() + k);
            k++;
            for(auto j : permute(temp)) {	// 递归 
                j.emplace(j.begin(), i);
                res.emplace_back(j);
            }
        }
    }
    return res;
}
int main()
{
	vector<int> nums {1,2,3};
	auto res = permute(nums);
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