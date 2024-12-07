class Solution {
public:
    int calculate(vector<int>& nums, int mid) {
        int result=0;
        for (auto&p:nums) {
            result+=(p-1)/mid; //number of splits
        }
        return result;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        /*
        this problem can not be solved using heap beacuse we do not have an idea of to divide the maximum in what manner , 
        like of we have 7 as the maximum element , we do not have the control that whether to divide it as 3,4 or as 6,1 .
        */
        //no. of bags i can have is maxOperations+n
        int n=nums.size();
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int result=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            int splitsneeded=calculate(nums,mid);
            if(splitsneeded>maxOperations){
                left=mid+1;
            }
            else{
                result=min(result,mid);
                right=mid-1;
            }
        }
        return result;
    }
};