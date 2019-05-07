// leetcode120.Triangle
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp{{triangle[0][0]}};
        int len = triangle.size();
        int res = dp[0][0];
        for(int i = 1; i < len; i++)
        {
            vector<int> temp(i+1, 0);
            res = INT_MAX;
            for(int j = 0; j < i+1; j++)
            {
                if(j != 0 && j != i)
                    temp[j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                else if(j == i)
                    temp[j] = triangle[i][j] + dp[i-1][j-1];
                else if(j == 0)
                    temp[j] = triangle[i][j] + dp[i-1][j];
                
                if(temp[j] < res)
                    res = temp[j];
            }
            dp.emplace_back(temp);
        }
        return res;
    }
};