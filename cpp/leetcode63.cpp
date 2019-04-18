class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        vector<vector<long long>> path(m, vector<long long>(n, 0));
        for(int i = 0; i < m; i++)
        {
            if(obstacleGrid[i][0] == 0) path[i][0] = 1;
            else {
                for(int j = i; j < m; j++) path[j][0] = 0;
                break;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(obstacleGrid[0][i] == 0) path[0][i] = 1;
            else {
                for(int j = i; j < n; j++) path[0][j] = 0;
                break;
            }
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1) continue;
                else path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m-1][n-1];
    }
};