class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(j!=i && grid[i][j]==0){
                    flag=false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};