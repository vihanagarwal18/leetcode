class Solution {
public:
    int solve(int len, int zero, int one, vector<int>& memo, int low, int high, int mod) {
        if (len > high) return 0;
        if (memo[len] != -1) return memo[len];
        int count = 0;
        if (len >= low) count = 1;
        count=(count+solve(len+zero,zero,one,memo,low,high,mod))%mod;
        count=(count+solve(len+one,zero,one,memo,low,high,mod))%mod;
        return memo[len] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int mod = 1e9 + 7;
        vector<int> memo(high + 1, -1);
        return solve(0,zero,one,memo,low,high,mod);
    }
};
