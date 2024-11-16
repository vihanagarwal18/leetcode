class Solution {
public:
    bool solve(int index,string& s,int& n,vector<vector<int>>& memo,int count){
        if(index==n){
            if(count==0) return true;
            else return false;
        }
        if(memo[index][count]!=-1) return memo[index][count];
        bool result=false;
        if(s[index]=='(') result=solve(index+1,s,n,memo,count+1);
        else if(s[index]==')'){
            if(count==0) return false;
            result=solve(index+1,s,n,memo,count-1);
        }
        else{
            result=result || solve(index+1,s,n,memo,count+1); //open bracket
            if(count>0)   result=result||solve(index+1,s,n,memo,count-1); //close bracket
            result=result || solve(index+1,s,n,memo,count); //nothing
        }
        memo[index][count]=result;
        return memo[index][count];
    }
    bool checkValidString(string s) {
        int n=s.size();
        //astrik has 3 option at each  stage
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return solve(0,s,n,memo,0);
        
    }
};