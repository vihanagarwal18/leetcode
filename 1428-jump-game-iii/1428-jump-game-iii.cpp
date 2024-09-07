class Solution {
public:
    bool solve(int index,vector<int>& memo,vector<int>& arr){
        if(arr[index]==0) return true;
        if(memo[index]!=-1) return memo[index];
        // int n=arr.size();
        bool forward=false;
        bool backward=false;
        memo[index]=0;
        if(index+arr[index]<arr.size()){
            forward=solve(index+arr[index],memo,arr);
        }
        if(index-arr[index]>=0){
            backward=solve(index-arr[index],memo,arr);
        }
        memo[index]=backward||forward;
        return memo[index];
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> memo(n,-1);
        return solve(start,memo,arr);
    }
};