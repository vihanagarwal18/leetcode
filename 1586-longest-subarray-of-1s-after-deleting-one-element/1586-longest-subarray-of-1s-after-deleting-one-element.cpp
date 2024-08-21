class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int non_one_count=0;
        int maxcount=0;
        int left=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=1) non_one_count++;
            while(non_one_count>1){
                if(nums[left]!=1) non_one_count--;
                left++;
            }
            
            maxcount=max(maxcount,i-left+1);
        }
        return maxcount-1;
    }
};