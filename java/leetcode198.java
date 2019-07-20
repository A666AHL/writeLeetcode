class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        int[] dp = new int[len];
        boolean[] next = new boolean[len];
        dp[0] = nums[0];
        if(nums[1] > nums[0]) {
            dp[1] = nums[1];
        }
        else{
            dp[1] = dp[0];
            next[1] = true;
        }
        for(int i = 2; i < len; i++)
        {
            // i 之前的最后一个被打劫
            // 可以选择打劫第i个而放弃打劫i-1
            if(nums[i] + dp[i-2] > dp[i-1]) {   // 放弃i-1去打劫i
                dp[i] = nums[i] + dp[i-2];
            }
            else {  // 依然打劫i-1
                dp[i] = dp[i-1];
                next[i] = true;
            }   
        }
        return dp[len-1];
    }
}