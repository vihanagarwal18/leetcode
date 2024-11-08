class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int sum=0;
        for(auto& p:nums) sum=sum^p;
        int maxx=pow(2,maximumBit)-1; //max possible value  
        vector<int> result;
        for(int i=0;i<n;i++){
            int k=sum^maxx;  //value which we need in extra to make it maximum
            result.push_back(k);
            sum=sum^nums[n-1-i];
        }
        return result;
    }
};