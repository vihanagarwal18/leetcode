class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> result(n,1);
        vector<pair<int,int>> temp(n);
        for(int i=0;i<n;i++){
            temp[i]={arr[i],i};
        }
        sort(temp.begin(),temp.end());
        int rank=1;
        for(int i=1;i<n;i++){
            if(temp[i-1].first<temp[i].first) rank++;
            result[temp[i].second]=rank;
        }
        return result;
    }
};