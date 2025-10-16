class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> check;
        for(auto& p:nums){
            if(p>=0) check[p%value]++;
            else check[((p%value)+value)%value]++;
        }
        int min_frequency=INT_MAX;
        int min_index=INT_MAX;
        for(int i=0;i<value;i++){
            if(check[i]==0) return i;
            if(check[i]<min_frequency){
                min_frequency=check[i];
                min_index=i;
            }
        }
        if(min_index==0){
            return min_frequency*value;
        }
        return (min_frequency*value)+min_index;
    }
};