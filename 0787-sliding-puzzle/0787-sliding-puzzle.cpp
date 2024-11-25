class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<pair<int, pair<vector<vector<int>>, pair<int, int>>>> q; 
        vector<vector<int>> required={{1,2,3},{4,5,0}};
        if (board==required) return 0;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    q.push({0,{board,{i,j}}});
                    break;
                }
            }
        }
        vector<vector<int>> direc={{0,1},{1,0},{-1,0},{0,-1}};
        set<vector<vector<int>>> visited;
        int result=INT_MAX;
        while(!q.empty()){
            int steps=q.front().first;
            auto p=q.front().second.first; //board
            int x=q.front().second.second.first;
            int y=q.front().second.second.second;
            q.pop();
            // if(p==required) result=min(result,steps);
            if(p==required) return steps;
            for(int i=0;i<4;i++){
                int r=x+direc[i][0];
                int c=y+direc[i][1];
                if(r>=0 && r<2 && c>=0 && c<3){
                    vector<vector<int>> copystate=p;
                    swap(copystate[x][y],copystate[r][c]);
                    if(visited.find(copystate)==visited.end()){
                        visited.insert(copystate);
                        q.push({steps+1,{copystate,{r,c}}});

                    }
                }
            }
            
        }
        if(result==INT_MAX) return -1;
        return result;
    }
};