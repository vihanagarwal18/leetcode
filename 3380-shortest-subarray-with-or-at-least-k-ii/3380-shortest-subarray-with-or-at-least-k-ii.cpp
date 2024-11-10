class Solution {
public:
    bool check(vector<long long>& count,int& k){
        int result=0;
        for(int i=0;i<32;i++){
            if(count[i]>0){
                result=result | (1<<i);
            }
        }
        if(result>=k) return true;
        return false;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        if (maxi >= k) return 1;
        int result=INT_MAX;
        int left=0;
        vector<long long> count(32,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                count[j]+=(1<<j)& nums[i];
            }
            while(left<n && check(count,k)){
                result=min(result,i-left+1);
                int index=0;
                for(int i=0;i<32;i++){
                    count[i]-= (1<<i)& nums[left];
                }
                left++;
            }
        }
        if(result==INT_MAX) return -1;
        return result;
    }
};