// leetcode152.Maximum Product Subarray
class Solution {
public:
     int maxProduct(vector<int>& nums) {
        vector<int> f, g;    // f当前最大，g当前最小
        f.emplace_back(nums[0]);
        g.emplace_back(nums[0]);
        for (int i=1; i<nums.size(); ++i) {
            f.emplace_back(max(max(f[i-1]*nums[i], g[i-1]*nums[i]), nums[i]));
            g.emplace_back(min(min(f[i-1]*nums[i], g[i-1]*nums[i]), nums[i]));        
        }
        int m = f[0];
        for (int i=1; i<f.size(); ++i) m = max(m, f[i]);
        return m;
    }
};