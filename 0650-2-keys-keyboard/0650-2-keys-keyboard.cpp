class Solution {
public:
    int solve(int current, int copy, int& n, vector<vector<int>>& memo) {
        if (current == n) return 0;
        if (memo[current][copy] != -1) return memo[current][copy];
        int copyy=INT_MAX;
        if (current!=copy) {
            int temp = solve(current, current, n, memo);
            if (temp!=INT_MAX) copyy=1+temp;
        }
        int paste = INT_MAX;
        if(current+copy<= n) {
            int temp = solve(current + copy, copy, n, memo);
            if (temp!=INT_MAX) paste=1+temp;
        }
        memo[current][copy] = min(copyy, paste);
        return memo[current][copy];
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        return 1 + solve(1,1,n,memo);
    }
};
