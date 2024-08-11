class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool solve(int i, int j, int index, string& word, vector<vector<char>>& board) {
        if (index == word.size()) return true; 
        char temp = board[i][j];
        board[i][j] = '#';
        for (int d = 0; d < 4; d++) {
            int r = i + directions[d][0];
            int c = j + directions[d][1];
            if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] == word[index]) {
                if (solve(r, c, index + 1, word, board)) return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && solve(i, j, 1, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};
