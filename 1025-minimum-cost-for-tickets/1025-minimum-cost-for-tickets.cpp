class Solution {
public:
    int solve(int index,vector<int>& days,vector<int>& costs,vector<vector<int>>& memo,int& n,int covered){
        if(index>=n || covered>=days[n-1]) return 0;
        if(memo[index][covered]!=-1) return memo[index][covered];
        if(days[index]<=covered){
            memo[index][covered]=solve(index+1,days,costs,memo,n,covered);
            return memo[index][covered];
        }
        int buy_one=costs[0]+solve(index+1,days,costs,memo,n,days[index]);
        int buy_week=costs[1]+solve(index+1,days,costs,memo,n,days[index]+6);
        int buy_month=costs[2]+solve(index+1,days,costs,memo,n,days[index]+29);
        memo[index][covered]=min(buy_one,min(buy_week,buy_month));
        return memo[index][covered];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<vector<int>> memo(n,vector<int>(days[n-1],-1));
        return solve(0,days,costs,memo,n,0);
    }
};