class Solution {
public:
    int solve(int index,vector<int>& arr,vector<int>& memo,int& d){
        if(memo[index]!=-1) return memo[index];
        int maximum=1;
        int n=arr.size();
        //forward jump
        for(int i=index+1;i<=min(n-1,index+d);i++){
            if(arr[i]>=arr[index]) break;
            int temp=1+solve(i,arr,memo,d);
            maximum=max(maximum,temp);
        }

        //backwarrd jump
        for(int i=index-1;i>=max(0,index-d);i--){
            if(arr[i]>=arr[index]) break;
            int temp=1+solve(i,arr,memo,d);
            maximum=max(maximum,temp);
        }
        memo[index]=maximum;
        return memo[index];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> memo(n,-1);
        int maximum=1;
        for(int i=0;i<n;i++){ //starting from every index
            int temp=solve(i,arr,memo,d);
            maximum=max(maximum,solve(i,arr,memo,d));
        }
        return maximum;
    }
};