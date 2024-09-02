class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> row;
        vector<int> column;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }
        vector<int> temp(m,0);
        for(auto& p:row){
            matrix[p]=temp;
        }
        for(auto& p:column){
            for(int i=0;i<n;i++){
                matrix[i][p]=0;
            }
        }
    }
};