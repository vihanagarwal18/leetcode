class Solution {
public:
    bool bfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        vector<pair<int,int>>checkKar;
        checkKar.push_back({row,col});

        while (!q.empty()) {
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (auto it : directions) {
                int new_row = curr_row + it.first;
                int new_col = curr_col + it.second;
                if ((new_row >= 0 and new_row < grid2.size()) and (new_col >= 0 and new_col < grid2[0].size()) and (!visited[new_row][new_col]) and (grid2[new_row][new_col] == 1)) {
                    visited[new_row][new_col] = true;
                    q.push({new_row, new_col});
                    checkKar.push_back({new_row,new_col});
                }
            }
        }
        //ese islands ke sarei  pair ko check kar lege ki vo grid1 main 1 hain na
        for(auto it:checkKar){
            if(grid1[it.first][it.second]!=1){
                return false;
            }
        }
        return true;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size(); 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] and grid2[i][j] == 1) {
                    if (bfs(i, j, grid1, grid2, visited)) {
                        islands++;
                    }
                }
            }
        }

        return islands;
    }
};