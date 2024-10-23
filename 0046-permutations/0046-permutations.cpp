class Solution {
public:
    void solve(vector<vector<int>>& result, int count, int& n, vector<int>& nums, vector<int>& temp, vector<bool>& visited) {
        if (count == n) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = true;
                solve(result, count + 1, n, nums, temp, visited);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> temp;
        solve(result, 0, n, nums, temp, visited);
        return result;
    }
};
