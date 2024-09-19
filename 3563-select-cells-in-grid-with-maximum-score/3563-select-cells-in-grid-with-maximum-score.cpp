class Solution {
public:
    int solve(int index,int mask,vector<vector<int>>& values,vector<vector<int>>& memo){
        if(index==values.size()) return 0;
        if(memo[index][mask]!=-1) return memo[index][mask];
        int sum=0;
        int row=values[index][1];
        if((1<<row) & mask){
            //yani phele se le rakha ese row se
            sum=solve(index+1,mask,values,memo); 
        }
        else{
            int j=index;
            while(j<values.size() && values[index][0]==values[j][0]) j++; //duplicate value nhi aye jisse
            long long nottake=solve(index+1,mask,values,memo);
            long long take=values[index][0]+solve(j,(1<<row)|mask,values,memo);
            sum=max(nottake,take);
        }
        return memo[index][mask]=sum;
    }
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> values;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                values.push_back({grid[i][j], i, j});
            }
        }
        sort(values.begin(), values.end());
        int bits=pow(2,m+1);
        vector<vector<int>> memo(m*n,vector<int>(bits,-1));
        return solve(0,0,values,memo);
    }
};