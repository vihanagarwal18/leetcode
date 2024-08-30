#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& stones, vector<int>& stone, vector<bool>& visited, int index) {
        visited[index] = true;
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i] && (stones[i][0] == stone[0] || stones[i][1] == stone[1])) {
                dfs(stones, stones[i], visited, i);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int groups = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(stones, stones[i], visited, i);
                groups++;
            }
        }

        return n - groups;
    }
};
