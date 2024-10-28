class Solution {
public:
    int solve(int i, vector<int>& nums, unordered_map<int, int>& memo, unordered_map<int, int>& m) {
        if (memo.find(nums[i]) != memo.end()) {
            return memo[nums[i]];
        }

        int squareRoot = sqrt(nums[i]);
        int maxStreak = 1;

        if (squareRoot * squareRoot == nums[i] && m.count(squareRoot)) {
            maxStreak = 1 + solve(m[squareRoot], nums, memo, m);
        }

        memo[nums[i]] = maxStreak;
        return maxStreak;
    }

    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int, int> memo;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            m[nums[i]] = i;
        }

        int maxStreak = 1;

        for (int i = 0; i < n; i++) {
            maxStreak = max(maxStreak, solve(i, nums, memo, m));
        }

        return maxStreak > 1 ? maxStreak : -1;
    }
};
