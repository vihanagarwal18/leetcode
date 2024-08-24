class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //this graph is adj matrix
        //terminal node has outdegree as 0
        int n=graph.size();
        vector<int> outdegree(n,0);
        vector<vector<int>> adj(n); //will store reverse adj means if 0 has 1 then we can reach 0 from 1
        for (int i=0;i<n;i++) {
            for (auto& q:graph[i]) {
                outdegree[i]++;
                adj[q].push_back(i);
            }
        }
        vector<int> result;
        set<int> terminalnodes;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0) {
                terminalnodes.insert(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front(); 
            terminalnodes.insert(node);
            q.pop();
            for(auto& p:adj[node]){
                outdegree[p]--;
                if(outdegree[p]==0){
                    q.push(p);
                }
            }
        }
        while(terminalnodes.size()>0){
            auto it=*terminalnodes.begin();
            result.push_back(it);
            terminalnodes.erase(it);
        }
        return result;
    }
};