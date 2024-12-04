class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(str1[i]==str2[j] || (str1[i]=='z' && str2[j]=='a') || str1[i]+1==str2[j]){
                j++;
            }
            i++;
        }
        if(j==m) return true;
        return false;
    }
};
/*
class Solution {
public:
    int solve(int i,int j,string& str1,string& str2,int& n,int& m,vector<vector<int>>& memo){
        if(j==m) return true;
        if(i==n) return false;
        if(memo[i][j]!=-1) return memo[i][j];
        bool res=false;
        if(str1[i]==str2[j] || (str1[i]=='z' && str2[j]=='a')|| str1[i]+1==str2[j]){
            res=solve(i+1,j+1,str1,str2,n,m,memo);
        }
        res=res || solve(i+1,j,str1,str2,n,m,memo);
        memo[i][j]=res;
        return memo[i][j];
    }
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return solve(0,0,str1,str2,n,m,memo);
    }
};
*/