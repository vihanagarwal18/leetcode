class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int pre=1;
        vector<int> result(n,1);
        for(int i=0;i<n;i++){
            result[i]=result[i]*pre;
            pre=pre*nums[i];
        }
        int suff=1;
        for(int i=n-1;i>=0;i--){
            result[i]=result[i]*suff;
            suff=suff*nums[i];
        }
        return result;
    }
};