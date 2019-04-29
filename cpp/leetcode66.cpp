// leetcode66
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        digits[len-1]++;
        vector<int> res;
        if(digits[len-1] == 10)
        {
            if(len == 1)
                return {1, 0};
            digits[len-1]=0;
            vector<int> temp{digits.begin(), --digits.end()};
            res=plusOne(temp);
        }
        else{
            return digits;
        }
        res.emplace_back(digits[len-1]);
        return res;
    }
};