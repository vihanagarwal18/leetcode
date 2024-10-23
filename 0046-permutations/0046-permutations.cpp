class Solution {
public:
    void solve(vector<vector<int>>& result,int count,int& n,vector<int>& nums,vector<int> temp,unordered_set<int>& u){
        if(count==n){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(u.find(nums[i])==u.end()){
                temp.push_back(nums[i]);
                u.insert(nums[i]);
                solve(result,count+1,n,nums,temp,u);
                temp.pop_back();
                u.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n=nums.size();
        unordered_set<int> u;
        vector<int> temp;
        solve(result,0,n,nums,temp,u);
        return result;
    }
};