class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=0;
        int result=1;
        while(left<n && right<n){
            while(right<n && nums[right]-2*k<=nums[left]) right++;
            result=max(result,right-left);
            left++;
        }
        return result;
    }
};
