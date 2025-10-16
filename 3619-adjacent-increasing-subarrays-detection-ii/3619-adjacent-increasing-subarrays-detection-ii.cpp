class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> increasing(n,1);
        int count=1;
        int max_array=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) count++;
            else count=1;
            increasing[i]=count;
            max_array=max(max_array,increasing[i]);
        }
        vector<int> consecutive;
        for(int i=0;i<n-1;i++){
            if(increasing[i]>=increasing[i+1]) consecutive.push_back(increasing[i]);
        }
        if(increasing[n-1]!=1) consecutive.push_back(increasing[n-1]);

        int m=consecutive.size();
        int result=1;
        for(int j=1;j<m;j++){
            result=max(result,min(consecutive[j-1],consecutive[j]));
        }

        // now we will check can one single array create 2 max arrays

        // if(max_array%2==0){
            result=max(result,max_array/2);
        // }
        // else result=max(result,(max_array+1)/2);

        return result;
    }
};