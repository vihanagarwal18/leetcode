class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int  count=1;
        vector<vector<int>> visited(n,vector<int>(n,0));
        long long total=n*n;
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        int i=0;
        int x=0;
        int y=0;
        while(count<=total){
            // result.push_back(matrix[x][y]);
            visited[x][y]=1;
            matrix[x][y]=count;
            count++;
            int row=x+directions[i][0];
            int column=y+directions[i][1];
            if(row>=n || column>=n || row<0 || column<0 || visited[row][column]==1){
                i=(i+1)%4;
            }
            x+=directions[i][0];
            y+=directions[i][1];
        }
        return matrix;
    }
};
