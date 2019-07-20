class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        int[] dp = new int[len];
        boolean[][] next = new boolean[len][len];
        dp[0] = nums[0];
        if(nums[1] > nums[0]) {
            dp[1] = nums[1];
            for(int i = 1; i < len; i++) {
                next[i][0] = true;
            }
        }
        else{
            dp[1] = dp[0];
            for(int i = 1; i < len; i++) {
                next[i][1] = true;
            }
        }
        if(len == 2) return dp[1];
        for(int i = 2; i < len; i++)
        {
            // i 之前的最后一个被打劫
            // 可以选择打劫第i个而放弃打劫i-1
            if(nums[i] + dp[i-2] > dp[i-1]) {   // 放弃i-1去打劫i
                dp[i] = nums[i] + dp[i-2];
                for(int j = i; j < len; j++) {
                    for(int k = 0; k < i-1; k++) {	// 如果回退，那么next需要回退到上一个
                        next[j][k] = next[i-2][k];
                    }
                	next[j][i-1] = true;
            	}
            }
            else {  // 依然打劫i-1
                dp[i] = dp[i-1];
                for(int j = i; j < len; j++) {
                    next[j][i] = true;
                }
            }   
        }
        System.out.println(dp[len-1]);
        System.out.println(next[len-1][0]);
        if(!next[len-1][0] && !next[len-1][len-1]) {	// 如果打劫了首尾，那么放弃其中一个
            nums[0] = 0;
            int temp = rob1(nums);	// 若放弃首，那么首将变为0，重新获取从1到len-1最大
            dp[len-1] = dp[len-2] > temp ? dp[len-2] : temp;
        }
        return dp[len-1];
    }
    // 没有首尾相连，即打家劫舍1
    public int rob1(int[] nums) {
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