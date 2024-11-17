class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int result=n+1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                sum-=nums[left];
                result=min(result,i-left+1);
                left++;
            }
        }
        if(result==n+1) return 0;
        return result; 
    }
};