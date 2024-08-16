class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        int minimum=arrays[0][0];
        int maximum=arrays[0].back();
        int result=0;
        for(int i=1;i<n;i++){
            result=max(result,abs(maximum-arrays[i][0]));
            result=max(result,abs(minimum-arrays[i].back()));
            minimum=min(minimum,arrays[i][0]);
            maximum=max(maximum,arrays[i].back());
        }
        return result;
    }
};