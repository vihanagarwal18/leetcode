class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(51, -1));
        return countWays(nums, 0, 0, memo, MOD,INT_MAX);
    }
    int countWays(const vector<int>& nums, int i, int last, vector<vector<int>>& memo, const int MOD,int lastincreasing) {
        if (i == nums.size()) return 1; 
        if (memo[i][last] != -1) return memo[i][last]; 
        int ways = 0;
        for (int x = last; x <= nums[i]; x++) { 
            if(nums[i]-x>lastincreasing) continue;
            ways = (ways + countWays(nums, i + 1, x, memo, MOD,nums[i]-x)) % MOD;
        }
        return memo[i][last] = ways; 
    }
};
