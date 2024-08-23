class Solution {
public:
    bool ispalindrome(int start, int end, string& s, vector<vector<int>>& memo) {
        if (start >= end) return true; 
        if (memo[start][end] != -1) return memo[start][end]; 
        if (s[start]==s[end]) {
            return memo[start][end] =ispalindrome(start+1,end-1,s,memo);
        }
        return memo[start][end] = false;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));  
        string res = "";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if(res.size()>=j-i+1) continue;
                if (ispalindrome(i, j, s, memo)) {
                    res = s.substr(i,j-i+1);  
                }
            }
        }
        return res;
    }
};
