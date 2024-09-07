class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return nums[0];  
        // if (k == 1 && n == 1) return -1; 
        if(n==1 && k%2==1) return -1;
        int maximum = -1;
        for (int i = 0; i < min(k-1, n); i++) {
            maximum = max(maximum, nums[i]);
        }
        if (k<n) {
            maximum=max(maximum,nums[k]);
        }
        return maximum;
    }
};
