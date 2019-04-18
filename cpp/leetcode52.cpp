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