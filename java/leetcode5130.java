class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int len = dominoes.length;
        int res = 0;
        boolean[] flag = new boolean[len];
        for(int i = 0; i < len-1; i++) {
            int temp = res;
            if(!flag[i]) {
                for(int j = i + 1; j < len; j++) {
                    if((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) || (dominoes[i][1] == dominoes[j][0] && dominoes[i][0] == dominoes[j][1])) {
                        res++;
                        flag[j] = true;
                    }
                }
            }
            int temp1 = res - temp;
            res = res - temp1 + (1+temp1)*temp1/2;
        }
        return res;
    }
}