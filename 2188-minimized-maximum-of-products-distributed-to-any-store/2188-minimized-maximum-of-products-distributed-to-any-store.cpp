class Solution {
public:
    int solve(vector<int>& quantities,int limit){
        int result=0;
        for(auto& p:quantities){
            result+=ceil((double)p/limit);
        }
        return result;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int left=1;
        int right=*max_element(quantities.begin(),quantities.end());
        int result=right;
        while(left<=right){
            int mid=left+(right-left)/2; //this is max quantity given to a store
            int stores=solve(quantities,mid);
            if(stores>n){
                left=mid+1;
                
            }
            else{
                right=mid-1;
                result=min(result,mid);
            }
        }
        return result;
    }
};