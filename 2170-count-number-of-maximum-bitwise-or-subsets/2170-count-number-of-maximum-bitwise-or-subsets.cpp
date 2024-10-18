class Solution {
public:
    int solve(vector<int>& nums,int index,int value,int& maxx,int n){
        if(value==maxx){
            return pow(2,n-index);
        }
        if(index==n) return 0;
        int take=solve(nums,index+1,value|nums[index],maxx,n);
        int nottake=solve(nums,index+1,value,maxx,n);
        return take+nottake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxx=0;
        for(auto& p:nums) maxx|=p; //this is the max possible or
        return solve(nums,0,0,maxx,n);
    }
};