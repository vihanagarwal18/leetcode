class Solution {
public:
    int solve(vector<int>& nums,int maxsum){
        int result=1;
        int total=0;
        for(auto& p:nums){
            if(total+p<=maxsum) total+=p;
            else{
                result++;
                total=p;
            }
        }
        return result;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int left=*max_element(nums.begin(),nums.end());
        long long right=0;
        for(auto& p:nums) right+=p;
        int result=right;
        while(left<=right){
            int mid=left+(right-left)/2;  //maxsum which is allowed in an array
            int no_of_arrays=solve(nums,mid);
            if(no_of_arrays>k) left=mid+1;
            else{
                result=min(result,mid);
                right=mid-1;
            }
        }
        return result;
    }
};