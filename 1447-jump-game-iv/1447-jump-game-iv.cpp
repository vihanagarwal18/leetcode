class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if (n==1) return 0;
        unordered_map<int,vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
        vector<int> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int jumps=0;
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                int index = q.front();
                q.pop();
                if (index==n-1) return jumps;
                vector<int>& nextIndices = m[arr[index]];
                nextIndices.push_back(index-1);
                nextIndices.push_back(index+1);
                for (int next : nextIndices) {
                    if (next >= 0 && next < n && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                m[arr[index]].clear(); //to reduce no. of calls again
                size--;
            }
            jumps++;
        }
        return -1;
    }
};

/*
class Solution {
public:
    int solve(int index, vector<int>& memo, vector<int>& arr, unordered_map<int, vector<int>>& m) {
        if (index >= arr.size() - 1) return 0; 
        if (memo[index] != -1) return memo[index]; 
        int minimum = INT_MAX;
        // +1 jump
        if (index + 1 < arr.size()) {
            int temp=1+solve(index + 1, memo, arr, m);
            minimum=min(minimum, temp);
        }
        // -1 jump
        if (index > 0) {
            int temp=1+solve(index-1,memo,arr,m);
            minimum=min(minimum,temp);
        }
        for (int next : m[arr[index]]) {
            if (next != index) {
                int temp = 1 + solve(next, memo, arr, m);
                minimum = min(minimum, temp);
            }
        }
        m[arr[index]].clear(); //to reduce no. of recurssive call
        memo[index] = minimum; 
        return memo[index];
    }

    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
        vector<int> memo(n, -1); 
        return solve(0, memo, arr, m);
    }
};


*/