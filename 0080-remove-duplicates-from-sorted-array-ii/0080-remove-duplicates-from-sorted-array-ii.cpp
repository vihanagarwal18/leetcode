class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int slow=0;
        int fast=2;
        int result=n;
        while( slow <n && fast<n){
            if(nums[slow]==nums[fast]){
                result--;
                nums.erase(nums.begin()+fast);
                slow--;
                fast--;
                n--;
            }
            slow++;
            fast++;
        }
        return nums.size();
    }
};