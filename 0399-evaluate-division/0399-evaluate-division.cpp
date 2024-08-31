class Solution {
public:
    double dfs(map<string, vector<pair<string, double>>>& graph,string& current,string& target,map<string,bool>& visited){
        if(visited[current]==true) return -1.0;
        visited[current]=true;
        for(auto& p:graph[current]){
            if(p.first==target) return p.second;
            double result=dfs(graph,p.first,target,visited);
            if(result!=-1.0) return p.second* result;
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> graph;
        vector<double> result;
        int i = 0;
        for (auto& p : equations) {
            graph[p[0]].push_back({p[1], values[i]});
            graph[p[1]].push_back({p[0], 1.0 / values[i]});
            i++;
        }
        for(auto& p:queries){
            map<string,bool> visited;
            if(graph.find(p[0])==graph.end() || graph.find(p[1])==graph.end() ){
                result.push_back(-1.0);
            }
            else if(p[0]==p[1]) result.push_back(1.0);
            else{
                double temp=dfs(graph,p[0],p[1],visited);
                result.push_back(temp);
            }
        }
        return result;
    }
};