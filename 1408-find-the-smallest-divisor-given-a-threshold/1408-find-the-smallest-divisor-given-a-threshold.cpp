class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int result=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            int thres=0;
            for(auto& p:nums){
                thres+=ceil((double)p/(double)mid);
            }
            if(thres>threshold) left=mid+1;
            else{
                result=min(result,mid);
                right=mid-1;
            }
        }
        return result;
    }
};