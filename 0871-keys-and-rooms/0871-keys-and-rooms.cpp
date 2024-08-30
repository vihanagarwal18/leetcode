class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<int>& visited,int index){
        visited[index]=1;
        for(auto p:rooms[index]){
            if(!visited[p]){
                dfs(rooms,visited,p);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visited(n,0);
        visited[0]=1;
        vector<int> temp(n,1);
        dfs(rooms,visited,0);
        if(visited==temp) return true;
        return false;
    }
};