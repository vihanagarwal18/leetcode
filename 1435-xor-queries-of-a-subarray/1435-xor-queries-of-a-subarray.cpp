class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> xorarray(n);
        int total=0;
        for(int i=0;i<n;i++){
            total=total^arr[i];
            xorarray[i]=total;
        }
        vector<int> result;
        for(auto& p:queries){
            int left=p[0];
            int right=p[1];
            int temp=xorarray[right];
            if(left>0){
                temp=temp^xorarray[left-1];
            }
            result.push_back(temp);
        }
        return result;
    }
};