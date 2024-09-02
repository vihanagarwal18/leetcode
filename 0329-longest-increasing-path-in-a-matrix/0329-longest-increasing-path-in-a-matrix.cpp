class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) return memo[i][j]; 
        int n = matrix.size();
        int m = matrix[0].size();
        int temp = 1; 
        for (auto& p : directions) {
            int x = i + p[0];
            int y = j + p[1];
            if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[i][j]) {
                temp = max(temp, 1 + dfs(x, y, matrix, memo)); 
            }
        }
        memo[i][j] = temp;
        return temp;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1)); 
        int maxx = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxx = max(maxx, dfs(i, j, matrix, memo));
            }
        }
        return maxx;
    }
};
