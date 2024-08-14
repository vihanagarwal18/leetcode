class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& memo) {
        int n = nums.size();
        if (index >= n - 1) return 0;
        if (memo[index] != -1) return memo[index];
        int minJumps = INT_MAX;
        for (int i = 1; i <= nums[index]; i++) {
            if (index + i < n) { // Ensure we don't go out of bounds
                int jumps = solve(index + i, nums, memo);
                if (jumps != INT_MAX) {
                    minJumps = min(minJumps, jumps + 1);
                }
            }
        }
        memo[index] = minJumps;
        return memo[index];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return solve(0, nums, memo);
    }
};
