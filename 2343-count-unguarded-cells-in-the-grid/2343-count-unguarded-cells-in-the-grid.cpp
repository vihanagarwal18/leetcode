class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (auto& p : walls) {
            visited[p[0]][p[1]] = 1;
        }
        for (auto& p : guards) {
            visited[p[0]][p[1]] = 1;
        }
        
        for (auto& p : guards) {
            for (auto& dir : directions) {
                int x = p[0];
                int y = p[1];
                while (true) {
                    x += dir[0];
                    y += dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == 1) {
                        break;
                    }
                    if (visited[x][y] == 0) {
                        visited[x][y] = 2;
                    }
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
