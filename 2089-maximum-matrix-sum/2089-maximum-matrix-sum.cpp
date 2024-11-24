class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> vect;
        long long sum=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    vect.push_back(abs(matrix[i][j]));
                    
                }
                sum+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
            }
        }
        int m=vect.size(); //all negative number
        if(m%2==1){
            sum-=2*mini;
        }
        return sum;
    }
};