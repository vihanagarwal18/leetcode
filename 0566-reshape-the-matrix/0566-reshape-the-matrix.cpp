class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if( r*c != n*m ||(n==r && m==c)) return mat;
        vector<vector<int>> result(r,vector<int>(c));
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[x][y]=mat[i][j];
                x++;
                if(x>=r){
                    x=0;
                    y++;
                }
            }
        }
        return result;
    }
};