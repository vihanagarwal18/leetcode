class Solution {
public:
    int solve(int index, int m, vector<vector<int>>& memo, vector<int>& piles,vector<int>& suffixsum) {
        int n = piles.size();
        if (index >= n) return 0;
        if (memo[index][m] != -1) return memo[index][m];
        int maxi = 0; 
        for (int x=1;x<=2*m && index+x<=n;x++) { 
            int temp=suffixsum[index]-solve(index+x,max(m,x),memo,piles,suffixsum);
            maxi = max(maxi,temp);
        }
        memo[index][m] = maxi;
        return maxi;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n,vector<int>(n+1,-1));
        vector<int> suffixsum(n);
        suffixsum[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suffixsum[i]=suffixsum[i+1]+piles[i];
        }
        return solve(0, 1, memo, piles,suffixsum);
    }
};
