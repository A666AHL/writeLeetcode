// leetcode174.Dungeon Game
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int len1 = dungeon.size();
        int len2 = dungeon[0].size();
        int dp[len1][len2];
        // 需要逆序dp
        dp[len1-1][len2-1] = dungeon[len1-1][len2-1] > 0 ? 1 : 1-dungeon[len1-1][len2-1];
        for(int i = len1-2; i >= 0; i--) {
            dp[i][len2-1] = dungeon[i][len2-1] >= dp[i+1][len2-1] ? 1 : dp[i+1][len2-1] - dungeon[i][len2-1];
        }
        for(int i = len2-2; i >= 0; i--) {
            dp[len1-1][i] = dungeon[len1-1][i] >= dp[len1-1][i+1] ? 1 : dp[len1-1][i+1] - dungeon[len1-1][i];
        }
        for(int i = len1-2; i >= 0; i--) {
            for(int j = len2-2; j>= 0; j--) {
                int temp = min(dp[i][j+1], dp[i+1][j]);
                dp[i][j] = dungeon[i][j] >= temp ? 1 : temp - dungeon[i][j];
            }
        }
        return dp[0][0];
    }
};