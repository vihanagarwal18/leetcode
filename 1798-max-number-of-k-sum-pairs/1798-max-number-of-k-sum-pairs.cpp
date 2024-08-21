class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int result=0;
        
        int left=0;
        int right=n-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum==k){
                left++;
                right--;
                result++;
            }
            else if(sum>k){
                right--;
            }
            else{
                left++;
            }
        }
        return result;
    }
};