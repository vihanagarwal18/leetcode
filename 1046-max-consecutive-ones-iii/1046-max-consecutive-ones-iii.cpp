class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countzero=0;
        int maxcount=0;
        int left=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                countzero++;
            }
            while(countzero>k){
                if (nums[left]==0){
                    countzero--;
                }
                left++;
            }
            maxcount=max(maxcount,i-left+1);
        }
        return maxcount;
    }
};