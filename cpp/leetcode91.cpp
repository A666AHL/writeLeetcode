// leetcode.91 解码方法
class Solution {
public:
    map<string, int> dp{{"0", 0}, {"1",1},{"2",1},{"3",1},{"4",1},{"5",1},{"6",1},{"7",1},{"8",1},{"9",1},{"10",1},{"11",2},{"12",2},{"13",2},{"14",2},{"15",2},{"16",2},{"17",2},{"18",2},{"19",2},{"20",1},{"21",2},{"22",2},{"23",2},{"24",2},{"25",2},{"26",2}};
    map<string, int> dp1;
    int numDecodings(string s) {
        int len = s.size();
        // 注意：第一位可能为‘0’
        if(len == 0 || s[0] == '0')
            return 0;
        if(dp.find(s) != dp.end())
        {
            return dp[s];
        }
        string s1 = s.substr(1, len-1), s2 = s.substr(2, len-2), s3 = s.substr(0, 2); 
		// 注意不能存入dp中，因为如果存入dp中，如“333”，{"3",1}{"33",1},此时
        // 第22行就会判断出错
        if(dp1.find(s1) == dp1.end())
            dp1[s1] = numDecodings(s1);
        if(dp1.find(s2) == dp1.end())
            dp1[s2] = numDecodings(s2);
        if(dp.find(s3) == dp.end())
            return dp1[s1];
        else 
            return dp1[s1] + dp1[s2];
    }
};

// 自底向上
class Solution {
public:
   int numDecodings(string &s) {
        if (s == "" || s[0] == '0') 
            return 0;
        
        int n = s.size();
        vector<int> f(n, 0);
        f[0] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0')
                f[i] += f[i-1];
            if (s[i-1] != '0' && stoi(s.substr(i-1, 2)) <= 26) 
                f[i] += i == 1 ? 1 : f[i-2];
            if (!f[i])
                return 0;
        }
        
        return f[n-1];
    }
};