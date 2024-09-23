class Solution {
public:
    int solve(int idx, string& s, vector<int>& memo, unordered_set<string>& u) {
        if (idx >= s.size()) return 0;
        if (memo[idx] != -1) return memo[idx];

        int mini = s.size() - idx;  // Worst case: all remaining characters are extra
        
        string current = "";
        for (int i = idx; i < s.size(); ++i) {
            current += s[i];
            if (u.find(current) != u.end()) {
                mini = min(mini, solve(i + 1, s, memo, u));  // No extra characters for this substring
            }
        }

        mini = min(mini, 1 + solve(idx + 1, s, memo, u));  // Treat s[idx] as an extra character
        return memo[idx] = mini;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> memo(n, -1);  // Memoization for minimum extra characters
        unordered_set<string> u(dictionary.begin(), dictionary.end());
        return solve(0, s, memo, u);
    }
};
