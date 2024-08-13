class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<string> row;
        vector<string> col;
        int n=grid.size();
        for(int i=0;i<n;i++){
            string rrow="";
            string ccol="";
            for(int j=0;j<n;j++){
                rrow+=to_string(grid[i][j])+",";
                ccol+=to_string(grid[j][i])+",";
            }
            row.push_back(rrow);
            col.push_back(ccol);
        }
        
        unordered_map<string,int> mr;
        unordered_map<string,int> mc;

        for(auto& p:row){
            mr[p]++;
        }
        for(auto& p:col){
            mc[p]++;
        }

        int result=0;
        for(auto& q:mr){
            int countrow=q.second;
            string rstring=q.first;
            if(mc.find(rstring)!=mc.end()){
                int countcol=mc[rstring];
                result+=countcol*countrow;
            }
        }
        return result;
    }
};