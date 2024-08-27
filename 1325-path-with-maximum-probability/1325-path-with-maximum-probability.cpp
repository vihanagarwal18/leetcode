class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        vector<double> maxprob(n, 0.0);
        maxprob[start_node] = 1.0;
        
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            double prob = p.first;
            int node = p.second;
            
            if (node == end_node) {
                return prob;
            }
            
            for (auto& n : adj[node]) {
                int next_node = n.first;
                double edgeprob = n.second;
                double newprob = prob * edgeprob;
                
                if (newprob > maxprob[next_node]) {
                    maxprob[next_node] = newprob;
                    pq.push({newprob, next_node});
                }
            }
        }
        
        return 0.0;
    }
};
