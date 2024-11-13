class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long result=0;
        for (int i=0;i<n;i++) {
            int lowbound=lower-nums[i];
            int highbound=upper-nums[i];
            int left=lower_bound(nums.begin()+i+1,nums.end(),lowbound)-nums.begin(); //will find smallest value greater than lowbound
            int right=upper_bound(nums.begin()+i+1,nums.end(),highbound)-nums.begin(); //will find smallest value greater than lowbound
            /*
            a lower bound is the smallest value that rounds up to an estimated value, while an upper bound is the smallest value that
            rounds up to the next estimated value
            */
            result+=right-left;
        }
        return result;
    }
};
