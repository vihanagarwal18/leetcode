class Solution {
public:
    bool solve(int index,vector<int>& memo,vector<int>& arr){
        if(arr[index]==0) return true;
        if(memo[index]!=-1) return memo[index];
        bool forward=false;
        bool backward=false;
        memo[index]=0;
        if(index+arr[index]<arr.size()){
            //can jump forward
            forward=solve(index+arr[index],memo,arr);
        }
        if(index-arr[index]>=0){
            backward=solve(index-arr[index],memo,arr);
        }
        memo[index]=forward || backward;
        return memo[index];
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> memo(n,-1);
        return solve(start,memo,arr);
    }
};