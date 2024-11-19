class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long sum = 0;
        long long result = 0;
        for (int i = 0; i < n;i++) {
            sum += nums[i];
            freq[nums[i]]++;
            if (i >= k) {
                sum-=nums[i-k];
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
            }
            if (freq.size()==k) result=max(result, sum);
        }
        return result;
    }
};
