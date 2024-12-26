class Solution {
public:
    int solve(vector<vector<int>>& memo,int index,int target,vector<int>& nums){
        if(index==0){
            if(target==0 && nums[0]==0){
                return 2;
            }
            if(target==nums[0] || target==0){
                return 1;
            }
            return 0;
        }
        if(memo[index][target]!=-1) return memo[index][target];
        int take=0;
        if(nums[index]<=target){
            take=solve(memo,index-1,target-nums[index],nums);
        }
        int nottake=solve(memo,index-1,target,nums);
        memo[index][target]=take+nottake;
        return memo[index][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        //sort(nums.begin(),nums.end());
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        if(total<target) return 0;
        if((total-target)%2==1) return 0; //as both the subset would never be equal
        int s2=(total-target)/2; //sum of negative subset needed
        vector<vector<int>> memo(n,vector<int>(s2+1,-1));
        return solve(memo,n-1,s2,nums);
    }
};