class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        int n=queries.size();
        vector<int> result(n,-1);
        for(int i=0;i<n;i++){
            int temp=abs(queries[i][0])+abs(queries[i][1]);
            pq.push(temp);
            if(pq.size()<k) continue;
            while(pq.size()>k) pq.pop();
            result[i]=pq.top();
        }
        return result;
    }
};