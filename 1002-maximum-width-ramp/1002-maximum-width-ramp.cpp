class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int maxx=nums[n-1];
        vector<int> arr(n);
        for(int i=n-1;i>=0;i--){
            maxx=max(maxx,nums[i]);
            arr[i]=maxx;
        }
        int result=0;
        int left=0;
        int right=0;
        while(right<n){
            if(nums[left]<=arr[right]){
                result=max(result,right-left);
                right++;
            }
            else{
                left++;
            }
        }
        return result;
    }
};