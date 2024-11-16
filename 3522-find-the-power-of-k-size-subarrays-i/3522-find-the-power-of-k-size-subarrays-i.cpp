class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1) return nums;
        bool isconsecutive=true;
        for(int i=1;i<k;i++){
            if(nums[i]!=nums[i-1]+1) {
                isconsecutive=false;
                break;
            }
        }
        vector<int> result;
        if(isconsecutive) result.push_back(nums[k-1]);
        else result.push_back(-1);

        for(int i=1;i<=n-k;i++){
            if(isconsecutive){
                if(nums[k+i-1]!=nums[k+i-2]+1) isconsecutive=false;
            }
            else{
                isconsecutive=true;
                for(int j=i+1;j<i+k;j++){
                    if(nums[j]!=nums[j-1]+1) {
                        isconsecutive=false;
                        break;
                    }
                }
            }
            if(isconsecutive) result.push_back(nums[i+k-1]);
            else result.push_back(-1);
        }
        return result;
    }
};