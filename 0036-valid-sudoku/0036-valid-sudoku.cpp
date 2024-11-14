class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //9 for rows
        // 9 for column
        //9 for each box
        vector<vector<set<char>>> vect(3,vector<set<char>>(9));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(vect[0][i].find(board[i][j])!=vect[0][i].end()) return false;
                if(vect[1][j].find(board[i][j])!=vect[1][j].end()) return false;
                int box = (i/3)*3+(j/3);
                if(vect[2][box].find(board[i][j])!=vect[2][box].end()) return false;
                vect[0][i].insert(board[i][j]);
                vect[1][j].insert(board[i][j]);
                vect[2][box].insert(board[i][j]);
            }
        }
        return true;
    }
};