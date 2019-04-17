class Solution {
public:
    int uniquePaths(int m, int n) {
        // 组合数问题
        m--;
        n--;
        // 求Cn/(m+n)
        int p = m < n ? m : n;
        long long res = 1; // 注意 整型溢出
        for(int i = m + n; i > m + n - p; i--) res *= i;
        for(int i = 1; i <= p; i++) res /= i;
        return res;
    }
};