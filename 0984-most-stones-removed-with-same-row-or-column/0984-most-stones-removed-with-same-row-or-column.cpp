class Solution {
public:
    void dfs(set<vector<int>>& u, vector<int> stone,set<vector<int>>& visited,vector<vector<int>>& stones) {
        for(auto& p:stones){
            if(visited.find(p)==visited.end() && (p[0]==stone[0] ||p[1]==stone[1])){
                u.erase(stone);
                visited.insert(stone);
                dfs(u,p,visited,stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        set<vector<int>> u(stones.begin(), stones.end());
        set<vector<int>> visited;
        int groups = 0;
        while (!u.empty()) {
            auto stone = *u.begin();
            dfs(u, stone,visited,stones);
            groups++;
        }
        return n - groups;
    }
};