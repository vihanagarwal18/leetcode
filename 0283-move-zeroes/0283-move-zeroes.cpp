class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        while(left<n){
            if(nums[left]==0 && left<n-1){
                int j=left+1;
                while(j<n-1 && nums[j]==0) j++;
                swap(nums[j],nums[left]);
            }
            left++;
        }
    }
};