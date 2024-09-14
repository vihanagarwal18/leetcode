class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        //maximum bitwise of this array would be max value
        int maxvalue=*max_element(nums.begin(),nums.end());
        //now need to find longest subaarray who only has 3
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=maxvalue){
                i=j+1;
            }
            else{
                result=max(result,j-i+1);
            }
        }
        return result;
    }
};