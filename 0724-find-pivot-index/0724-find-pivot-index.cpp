class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int prefix=0;
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        for(int i=0;i<n;i++){
            int left=prefix;
            prefix+=nums[i];
            int right=total-prefix;
            if(left==right) return i;
        }
        return -1;
    }
};