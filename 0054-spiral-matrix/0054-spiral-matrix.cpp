class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> result;
        vector<vector<int>> visited(n,vector<int>(m,0));
        long long total=n*m;
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        int i=0; // direction[i] we would take
        int count=0;
        int x=0;
        int y=0;
        while(count<total){
            result.push_back(matrix[x][y]);
            visited[x][y]=1;
            count++;
            int row=x+directions[i][0];
            int column=y+directions[i][1];
            if(row>=n || column>=m || row<0 || column<0 || visited[row][column]==1){
                i=(i+1)%4;
            }
            x+=directions[i][0];
            y+=directions[i][1];
        }
        return result;

    }
};