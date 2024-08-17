class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        vector<vector<long long>> memo(n+1,vector<long long>(m+1,0));
        for(int j=0;j<m;j++){
            memo[0][j]=points[0][j];
        }
        //For every row after 0th we traverse from both sides and take maximum
        for(int i=1;i<n;i++){
            vector<long long> leftmax(m);
            vector<long long> rightmax(m);
            leftmax[0]=memo[i-1][0];
            for(int j=1;j<m;j++){
                leftmax[j]=max(leftmax[j-1]-1,memo[i-1][j]);
            }
            rightmax[m-1]=memo[i-1][m-1];
            for(int j=m-2;j>=0;j--){
                rightmax[j]=max(rightmax[j+1]-1,memo[i-1][j]);
            }
            for(int j=0;j<m;j++){
                memo[i][j]=points[i][j]+max(leftmax[j],rightmax[j]);
            }
        }

        long long result=0;
        for(int j=0;j<m;j++){
            result=max(result,memo[n-1][j]);
        }
        return result;
    }
};

/*
class Solution {
public:
    long long solve(int i, int j, vector<vector<long long>>& memo, vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();  
        if (i==n-1) return 0;  
        if (memo[i][j]!=-1) return memo[i][j];
        long long maxi =LLONG_MIN;
        for (int k=0;k<m;k++) {
            long long temp =points[i+1][k]+solve(i+1,k,memo,points)-abs(j-k);
            maxi = max(maxi, temp);
        }
        memo[i][j] = maxi;
        return memo[i][j];
    }

    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> memo(n, vector<long long>(m, -1));
        long long maxi = LLONG_MIN;
        for (int i = 0; i < m; i++) {
            long long temp = points[0][i] + solve(0, i, memo, points);
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};

*/