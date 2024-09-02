class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<bool> temp(n,false);
        for(auto& p:nums){
            temp[p-1]=true;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(temp[i]==false) res.push_back(i+1);
        }
        return res;
    }
};