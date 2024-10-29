class Solution {
public:
    vector<vector<int>> directions={{-1,1},{0,1},{1,1}};
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& memo){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int maxi=0;
        for(auto& k:directions){
            int x=i+k[0];
            int y=j+k[1];
            if(x>=0 && y>=0 && x<n && y<m && grid[i][j]<grid[x][y]){
                int temp=1+solve(x,y,grid,memo);
                maxi=max(maxi,temp);
            }
        }
        memo[i][j]=maxi;
        return memo[i][j];
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        int result=INT_MIN;
        for(int i=0;i<n;i++){
            result=max(result,solve(i,0,grid,memo));
        }
        return result;
    }
};