// leetcode121.Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
            return 0;
        int min = prices[0];
        int res = 0;
        for(int i = 1; i < len; i++)
        {
            if(prices[i] < min)
                min = prices[i];
            int temp = prices[i] - min;
            if(temp > res)
                res = temp;
        }
        return res;
    }
};