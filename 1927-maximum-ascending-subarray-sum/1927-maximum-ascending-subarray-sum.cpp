class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int previousnumber=-1;
        int result=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>previousnumber) sum+=nums[i];
            else sum=nums[i];
            previousnumber=nums[i];
            result=max(result,sum);
        }
        return result;
    }
};