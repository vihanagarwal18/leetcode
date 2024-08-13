class Solution {
public:
    void solve(int index,vector<vector<int>>& res,vector<int>& candidates,vector<int> temp,int target){
        if(index==candidates.size()){
            if(target==0){
                res.push_back(temp);
            }
            return;
        }
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            solve(index,res,candidates,temp,target-candidates[index]); //repeated (taken also)
            temp.pop_back();   
        }
        solve(index+1,res,candidates,temp,target);//not taken

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0,res,candidates,temp,target);
        return res;
    }
};