class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> prefixcountpair;
        prefixcountpair.push_back(0); //dummy
        int count=0;
        for(int i=1;i<n;i++){
            if((nums[i-1]%2==0 && nums[i]%2==1) || (nums[i]%2==0 && nums[i-1]%2==1)){
                count++;
            }
            prefixcountpair.push_back(count);
        }
        vector<bool> result;
        for(auto& p:queries){
            if(prefixcountpair[p[1]]-prefixcountpair[p[0]]==p[1]-p[0]) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};