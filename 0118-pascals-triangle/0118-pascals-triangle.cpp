class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=result[i-1][j-1]+result[i-1][j];
            }
            result.push_back(temp);
        }
        return result;
    }
};