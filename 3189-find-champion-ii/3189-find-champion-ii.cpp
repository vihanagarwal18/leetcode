class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(auto& p:edges){
            indegree[p[1]]++;
        }
        int result=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(result!=-1) return -1;
                result=i;
            }
        }
        return result;
    }
};