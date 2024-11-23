class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> result(m, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            int emptyspot = m - 1;
            for (int j=m-1;j>=0;j--) {
                if (box[i][j]=='*') {
                    result[j][n-1-i]='*';
                    emptyspot=j-1;
                } 
                else if (box[i][j] == '#') {
                    result[emptyspot][n-1-i]='#';
                    emptyspot--;
                }
            }
        }
        return result;
    }
};
