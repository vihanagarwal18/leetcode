class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0] != 0) return -1;
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        set<vector<int>> u;
        u.insert({0,0,0});
        vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[0][0]=1;
        while(!u.empty()){
            auto p=*u.begin();
            u.erase(p);
            int x=p[1];
            int y=p[2];
            int time=p[0];
            visited[x][y]=1;
            if(x==n-1 && y==m-1) return time;
            for(int i=0;i<4;i++){
                int r=x+directions[i][0];
                int c=y+directions[i][1];
                if(r>=0 && r<n && c>=0 && c<m && visited[r][c]==0){
                    if(time+1>=grid[r][c] ){
                        u.insert({time+1,r,c});
                    }
                    else{
                        int rem=grid[r][c]-time;
                        if(rem%2==0){
                            u.insert({grid[r][c]+1,r,c});
                        }
                        else{
                            u.insert({grid[r][c],r,c});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
