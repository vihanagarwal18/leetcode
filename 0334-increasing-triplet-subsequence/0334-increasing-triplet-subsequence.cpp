class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int first=INT_MAX;
        int second=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<=first){
                first=nums[i];
            }
            else if(nums[i]<=second){
                second=nums[i];
            }
            else return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool solve(int index,vector<int>& nums,int& n,int pick,int last){
//         if(pick==3) return true;
//         if(index==n) return false;

//         bool take=false;
//         if(nums[index]>last){
//             take=solve(index+1,nums,n,pick+1,nums[index]);
//         }
//         bool nottake=solve(index+1,nums,n,pick,last);

//         return take||nottake;
//     }
//     bool increasingTriplet(vector<int>& nums) {
//         int n=nums.size();
//         return solve(0,nums,n,0,INT_MIN);
//     }
// };