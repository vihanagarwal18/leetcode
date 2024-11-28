class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<vector<int>> u;
        u.insert({0,0,0});
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> visited(n,vector<int>(m,INT_MAX));
        while(!u.empty()){
            auto p=*u.begin();
            u.erase(p);
            int x=p[1];
            int y=p[2];
            int dis=p[0];
            if(x==n-1 && y==m-1) return dis;
            for(int i=0;i<4;i++){
                int r=x+directions[i][0];
                int c=y+directions[i][1];
                if(r<n && r>=0 && c<m && c>=0 ){
                    if(grid[r][c]==0 && visited[r][c]> dis){
                        u.insert({dis,r,c});
                        visited[r][c]=dis;
                    }
                    else if(visited[r][c]> dis+1){
                        u.insert({dis+1,r,c});
                        visited[r][c]=dis+1;
                    }
                }
            }
        }
        return -1;
    }
};