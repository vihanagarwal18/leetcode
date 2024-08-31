class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[entrance[0]][entrance[1]]=1;
        queue<vector<int>> q;
        q.push({entrance[0],entrance[1],0});
        vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto p=q.front();
            int step=p[2];
            q.pop();
            // if((p[0]==0 || p[0]==n-1 || p[1]==0 ||p[1]==m-1) && (entrance[0]!=p[0] && entance[1]!=p[1])){
            //     return p[2];
            // }
            for(auto& direc:directions){
                int x=p[0]+direc[0];
                int y=p[1]+direc[1];
                if(step>0 && (x==n || x==-1 || y==-1 ||y==m)) return step;
                if(x>=0 && y>=0 && x<n && y<m && maze[x][y]=='.' && visited[x][y]!=1){
                    q.push({x,y,step+1});
                    visited[x][y]=1;
                }
            }
        }
        return -1;
    }
};