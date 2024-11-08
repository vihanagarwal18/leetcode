class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int k=n*m;
        int mod=12345;
        vector<int> prefix;
        vector<int> suffix(k);
        int product=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix.push_back(product);
                product=(product*(grid[i][j]%mod))%mod;
            }
        }
        int index=k-1;
        product=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suffix[index]=product;
                product=(product*(grid[i][j]%mod))%mod;
                index--;
            }
        }
        vector<vector<int>> result(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx=(i*m)+j;
                result[i][j]=(prefix[idx]*suffix[idx])%mod;
            }
        }
        return result;
    }
};