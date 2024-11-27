class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int> distances;
        for(auto p:queries){
            //after each addition we have to calculate distance
            adj[p[0]].push_back(p[1]);
            vector<int> dis(n,INT_MAX);
            dis[0]=0;
            set<pair<int,int>> s; // dis node
            s.insert({0,0});
            while(!s.empty()){
                auto it=*s.begin();
                s.erase(it);
                int node=it.second;
                int distance=it.first;
                if(node==n-1) {
                    distances.push_back(distance);
                    break;
                }
                for(auto q:adj[node]){
                    if(distance+1<dis[q]){
                        if(dis[q]!=INT_MAX){
                            s.erase({dis[q],q});
                        }
                        dis[q]=distance+1;
                        s.insert({dis[q],q});
                    }
                }
            }
            if(dis[n-1]==INT_MAX) distances.push_back(-1);
        }
        return distances;
    }
};