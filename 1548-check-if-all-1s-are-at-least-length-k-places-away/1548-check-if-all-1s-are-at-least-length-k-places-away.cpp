class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int gap=0;
        int left=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(left==-1){
                   left=i; 
                }
                else if(gap<k) return false;
                gap=0;
            }
            else{
                gap++;
            }
        }
        return true;
    }
};