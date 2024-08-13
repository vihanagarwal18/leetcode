class Solution {
public:
    void solve(int index,vector<vector<int>>& res,vector<int>& candidates,int target,vector<int> temp){
        if(target==0){
            res.push_back(temp);
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])  continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            solve(i+1,res,candidates,target-candidates[i],temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(0,res,candidates,target,temp);
        return res;
    }
};