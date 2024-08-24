class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>memo(n,vector<int>(m,0));//memo[i][j] tells how many squares end at i,j(rightbottom)
        //sum of memo would be our answer
        for(int i=0;i<n;i++){
            memo[i][0]=matrix[i][0];
        }
        for(int i=0;i<m;i++){
            memo[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){ 
                    int minimal=min(memo[i-1][j-1],min(memo[i-1][j],memo[i][j-1]));
                    memo[i][j]=minimal+1;
                }
            }
        }
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result+=memo[i][j];
            }
        }
        return result;
    }
};