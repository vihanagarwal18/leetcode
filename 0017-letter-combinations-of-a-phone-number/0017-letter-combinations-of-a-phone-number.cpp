class Solution {
public:
    void solve(vector<string>& result,int index,int& n,map<int,string>& m,string combination,string& digits){
        if(index>=n) return;
        int t=digits[index]-'0';
        string temp=m[t];
        for(int i=0;i<temp.size();i++){
            if(index==n-1){
                result.push_back(combination+temp[i]);
            }
            else{
                solve(result,index+1,n,m,combination+temp[i],digits);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        vector<string> result;
        int n=digits.size();
        solve(result,0,n,m,"",digits);
        return result;
    }
};