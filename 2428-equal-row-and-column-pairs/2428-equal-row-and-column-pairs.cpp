class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<string,int> mrow;
        map<string,int> mcol;
        for(int i=0;i<n;i++){
            string r="";
            string c="";
            for(int j=0;j<n;j++){
                r+=to_string(grid[i][j])+"#";
                c+=to_string(grid[j][i])+"#";
            }
            mrow[r]++;
            mcol[c]++;
        }
        int result=0;
        for(auto& p:mrow){
            int countr=p.second;
            string row=p.first;
            if(mcol.find(row)!=mcol.end()){
                result+=countr*mcol[row];
            }
        }
        return result;
    }
};