class Solution {
public:
    int countdistance(vector<int>& nums,int target){
        //no. of pairs with distance less than or equal to this target 
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
                //k-th smallest distance must be larger so to decrease difference increase lowest
                lowest=mid+1;
            }
            else{
                highest=mid-1;
            }
        }
        return lowest;
    }
};