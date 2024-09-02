class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int result = 0;
        unordered_map<int, int> m; //sum count
        m[0] = 1; 
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; 
            if (m.find(sum - k) != m.end()) {
                result += m[sum - k];
            }
            m[sum]++;
        }

        return result;
    }
};
