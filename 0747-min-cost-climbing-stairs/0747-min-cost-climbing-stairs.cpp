class Solution {
public:
    int solve(int index,vector<int>& cost,int& n,vector<int>& memo){
        if(index>=n) return 0;
        if(memo[index]!=-1) return memo[index];
        int plusone=cost[index]+solve(index+1,cost,n,memo);
        int plustwo=cost[index]+solve(index+2,cost,n,memo);
        memo[index]=min(plusone,plustwo);
        return memo[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> memo(n,-1);
        return min(solve(0,cost,n,memo),solve(1,cost,n,memo));
    }
};