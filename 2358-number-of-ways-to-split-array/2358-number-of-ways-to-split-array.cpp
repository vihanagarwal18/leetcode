class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long total=0;
        for(auto& p:nums) total+=p;
        long long  sum=0;
        int count=0;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            if(sum>=total-sum) count++;
        }
        return count;
    }
};