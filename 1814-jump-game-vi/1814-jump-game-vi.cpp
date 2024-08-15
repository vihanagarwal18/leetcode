// class Solution {
// public:
//     int solve(int index,vector<int>& nums,int& k,vector<int>& memo,int& n){
//         if(index==n-1) return nums[n-1];
//         if(memo[index]!=INT_MIN) return memo[index];
//         int maximum=INT_MIN;
//         for(int i=index+1;i<=min(n-1,index+k);i++){
//             int temp=nums[index]+solve(i,nums,k,memo,n);
//             maximum=max(maximum,temp);
//         }
//         memo[index]=maximum;
//         return memo[index];
//     }
//     int maxResult(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<int> memo(n,INT_MIN);
//         return solve(0,nums,k,memo,n);   
//     }
// };

class Solution {
public:
    int maxResult(std::vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> memo(n,INT_MIN);
        memo[n-1] = nums[n-1];
        deque<int> dq;
        dq.push_back(n-1);
        for (int i = n - 2; i >= 0; --i) {
            // Ensure the deque only contains indices within the range [i+1, i+k]
            if (!dq.empty() && dq.front() > i + k) {
                dq.pop_front();
            }
            // memo[i] is nums[i] + the maximum dp[j] for j in the range [i+1, i+k]
            memo[i] = nums[i] + memo[dq.front()];
            // Maintain the deque as a decreasing order of dp values
            while (!dq.empty() && memo[i] >= memo[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return memo[0];
    }
};
