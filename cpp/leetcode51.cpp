class Solution {
public:
    bool enableFun(int row, int j, string* chess2, int n)
    {
        for(int i = 0; i < n; ++i)
        {
            if(chess2[i][j] == 'Q')
                return false;
        }
        // top left
        for(int i=row,k=j;i>=0&&k>=0;i--,k--)
        {
            if(chess2[i][k] == 'Q')
                return false;
        }
        // top right
        for(int i=row,k=j;i>=0&&k<n;i--,k++)
        {
            if(chess2[i][k] == 'Q')
                return false;
        }
        // bottom left
        for(int i=row,k=j;i<n&&k>=0;i++,k--)
        {
            if(chess2[i][k] == 'Q')
                return false;
        }
        // bottom right
        for(int i=row,k=j;i<n&&k<0;i++,k++)
        {
            if(chess2[i][k] == 'Q')
                return false;
        }
        return true;
    }
    vector<vector<string>> results;
    void recursiveFun(int row, int n, string* chess)
    {
        string* chess2 = new string [n];
        for(int i = 0; i < n; ++i)
        {
            chess2[i] = chess[i];
        }
        if(row == n)
        {
            vector<string> one_of_results;
            for(int i = 0; i < n; ++i)
            {
                one_of_results.emplace_back(chess[i]);
            }
            results.emplace_back(one_of_results);
        }
        else{
            for(int j = 0; j < n; ++j)
            {
                if(enableFun(row, j, chess2, n))
                {
                    for(int k = 0; k < n; ++k)
                    {
                        chess2[row][k] = '.';
                    }
                    chess2[row][j] = 'Q';
                    recursiveFun(row+1, n, chess2);
                }
            }
        }
        delete [] chess2;
    }
    vector<vector<string>> solveNQueens(int n) {
        string* chess = new string [n];
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                chess[i] += '.';
            }
        }
        recursiveFun(0, n, chess);
        delete [] chess;
        return results;
    }
};