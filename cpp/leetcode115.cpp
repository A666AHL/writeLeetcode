// leetcode115.Distinct Subsequences
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s == t)
            return 1;
        int len1 = s.size();
        int len2 = t.size();
        
        long long dp[len1+1][len2+1];
        dp[0][0] = 1;
        for(int i = 0; i < len1; i++)
        {
            dp[i+1][0] = 1;
        }
        
        for(int i = 0; i < len2; i++)
        {
            dp[0][i+1] = 0;
        }
        
        for(int i = 0; i < len1; i++)
        {
            for(int j = 0; j < len2; j++)
            {
                if(s[i] == t[j])
                {
                    dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
                }
                else{
                    dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }
        return dp[len1][len2];
    }
};