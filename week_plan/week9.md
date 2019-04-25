## week9_question

leetcode64、70、72、85

## week9_exercise

- leetcode周赛133
- 2019 力扣杯 决赛

## week9_shared

- gcc 扩展语法中，数组的大小是可以为变量的

- 两种动态规划写法

  - 自顶向下（易于理解）

  ```c++
  // leetcode70.爬楼梯
  class Solution {
  public:
      int dp[100] = {1,2};
      int climbStairs(int n) {
          if(n == 1)
              return 1;
          if(n == 2)
              return 2;
          if(dp[n] == 0)
              dp[n] = climbStairs(n-1) + climbStairs(n-2);
          return dp[n];
      }
  };
  ```

  - 自底向上（用的较多，由于不用递归，也较优）

  ```c++
  // leetcode70.爬楼梯
  class Solution {
  public:
      int climbStairs(int n) {
          vector<int> dp(n,0);
          dp[0] = 1;
          if(n>1){
              dp[1] = 2;
              for(int i = 2; i < n; i++)
                  dp[i] = dp[i-1] + dp[i-2];
          }
          return dp[n-1];
      }
  };
  ```

  