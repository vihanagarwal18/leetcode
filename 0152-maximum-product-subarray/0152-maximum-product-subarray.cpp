class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int  prefix=1;
        int suffix=1;
        int res=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix = 1;
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            // double temp=prefix;
            // if(prefix<suffix) temp=suffix;
            // if(res<temp) res=temp;
            res=max(res,max(prefix,suffix));
        }
        return res;    
    }
};