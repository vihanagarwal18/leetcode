class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int result = 0;
        set<pair<int, int>> u;
        for (auto& obs : obstacles) {
            u.insert({obs[0], obs[1]});
        }
        int x = 0, y = 0, i = 0;
        for (auto& p : commands) {
            if (p == -1) i=(i+1)%4;
            else if (p == -2) i=(i+3)%4;
            else {
                for (int j = 0; j < p; ++j) {
                    int row = x + directions[i][0];
                    int column = y + directions[i][1];
                    if (u.find({row, column}) == u.end()) {
                        x = row;
                        y = column;
                        result = max(result,x*x+y*y);
                    } 
                    else break;
                }
            }
        }
        return result;
    }
};
