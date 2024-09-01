class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len=original.size();
        if(len!=m*n) return {};
        vector<vector<int>> result(m,vector<int>(n,0));
        int row=0;
        int column=0;
        for(int i=0;i<len;i++){
            result[row][column]=original[i];
            column++;
            if(column==n){
                column=0;
                row++;
            }
        }
        return result;
    }
};