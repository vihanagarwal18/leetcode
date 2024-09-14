class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        int maxx=-1;
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxx){
                result=1;
                j=i;
                maxx=nums[i];
            }
            else if(nums[i]==maxx){
                result=max(result,i-j+1);
            }
            else{
                j=i+1;
            }
        }
        return result;
    }
};