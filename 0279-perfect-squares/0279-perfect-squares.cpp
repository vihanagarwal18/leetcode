class Solution {
public:
    int solve(vector<int>& memo,int rem){
        if(rem==0) return 0;
        if(memo[rem]!=-1) return memo[rem];
        int i=2;
        int mini=rem;
        while(i*i<=rem){
            int temp=1+solve(memo,rem-i*i);
            mini=min(mini,temp);
            i++;
        }
        return memo[rem]=mini;
    }
    int numSquares(int n) {
        vector<int> memo(n+1,-1);
        memo[0]=0;
        memo[1]=1;
        return solve(memo,n);

    }
};