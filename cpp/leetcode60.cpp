class Solution {
public:
    string res {};
    void fun1(int n, int k, vector<int>& b)
    {
        if(b.empty())
            return;
        int a = 1;
        for(int i = 1; i < n; i++)
        {
            a *= i;
        }
        int first = k / a;
        res += to_string(b[first]);
        b.erase(begin(b)+first);
        n--;
        k -= first * a;
        fun1(n,k,b);
    }
    string getPermutation(int n, int k) {
        vector<int> b;
        for(int i = 1; i <= n; i++)
        {
            b.emplace_back(i);
        }
        k--;
        fun1(n, k, b);
        return res;
    }
};