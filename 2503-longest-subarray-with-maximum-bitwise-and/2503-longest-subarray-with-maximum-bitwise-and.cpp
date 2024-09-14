class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        int maxx=-1;
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxx){
                result=1;
                j=i;
                maxx=nums[i];
            }
            else if(nums[i]==maxx){
                result=max(result,i-j+1);
            }
            else{
                j=i+1;
            }
        }
        return result;
    }
};

/*
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
*/