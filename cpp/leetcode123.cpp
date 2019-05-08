// leetcode123.Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        vector<int> dp(len, 0);
        int least = prices[0];
        int res = 0;
        for(int i = 1; i < len; i++)
        {
            least = min(least, prices[i]);
            dp[i] = max(dp[i-1], prices[i] - least);
            res = max(res, dp[i]);
        }
        int most = prices[len-1];
        for(int i = len - 2; i > 0; i--)
        {
            most = max(most, prices[i]);
            int temp = most - prices[i] + dp[i-1];
            res = max(res, temp);
        }
        return res;
    }
};