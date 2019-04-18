## week8_question

leetcode51~63

## week8_exercise

- leetcode周赛132

- 2019 力扣杯 初赛

## week8_shared

- leetcode63
  - 此题跟第62题区别不大，但是第62题可以使用组合数快速写出来，而此题使用动态规划比较简单

  - 首先，若没有障碍的情况下到达`path[i][j]`有两种方式

    - 从左边到达
    - 从上边到达

    故有`path[i][j] = path[i-1][j] + path[i][j-1]`

    大体思路有了，然后处理一些特殊情况

    1. 如果起始点和终点有障碍，直接`return 0`

    2. 上边界与左边界作为初始数据，且若无障碍都应初始化为1，

       但是若边界出现障碍，则后面部分应初始化为0

    3. 循环遍历，若有障碍跳过此次循环

  - 代码如下：

```c++
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
```

- leetcode52
  - 使用回溯方法比较简单易于理解
  - 一些细节问题
    1. `a[k] = i ` 表示 第k 行在 第 i 列放置一个皇后
    2. 比较斜线可以使用斜率，因为 `k = 1`所以 `abs(row-i) == abs(col-a[i])`

```c++
class Solution {
public:
    bool check(int row, int col, vector<int>& a) {
        for(int i = 0; i < row; i++)
        {
            if(col == a[i] || abs(row-i) == abs(col-a[i]))
                return false;
        }
        return true;
    }
    int res=0;
    void f(int k, int n, vector<int>& a)
    {
        if(k == n)
        {
            res++;
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(check(k, i, a)) {
                a[k] = i;
                f(k+1, n, a);
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> a(n, 0);
        f(0, n, a);
        return res;
    }
};
```

