class Solution {
public:
    void dfs(int& result,vector<vector<pair<int,int>>>& adj,int node,vector<int>& visited){
        visited[node]=1;
        for(auto& p:adj[node]){
            if(!visited[p.first]){
                if(p.second==-1) result++;
                dfs(result,adj,p.first,visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);//node direction
        for(auto& p:connections){
            adj[p[0]].push_back({p[1],-1});//-1 means revere edge 
            adj[p[1]].push_back({p[0],1}); 
        }
        int result=0;
        vector<int> visited(n,0);
        visited[0]=1;
        dfs(result,adj,0,visited);
        return result;
    }
};