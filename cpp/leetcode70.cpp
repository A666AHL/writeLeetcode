// leetcode70.爬楼梯
// 自顶向下
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
// 自底向上
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