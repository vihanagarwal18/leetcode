class Solution {
public:
    int countdistance(vector<int>& nums,int target){
        int count=0;
        int left=0;
        int right=1;
        while(right<nums.size()){
            while(nums[right]-nums[left]>target){
                left++;
            }
            count+=right-left;
            right++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lowest=0;
        int highest=nums[n-1]-nums[0]; //max difference
        while(lowest<=highest){
            int mid=(lowest+highest)/2;
            if(countdistance(nums,mid)<k){
                lowest=mid+1;
            }
            else{
                highest=mid-1;
            }
        }
        return lowest;
    }
};