class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int count=0;
        long long sum=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0)  count++;
                sum+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
            }
        }
        if(count%2==1){
            sum-=2*mini;
        }
        return sum;
    }
};