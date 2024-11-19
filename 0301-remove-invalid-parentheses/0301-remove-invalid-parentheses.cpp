class Solution {
public:
    set<string> u;
    void f(string& s,string& temp,int i,int lcount,int rcount,int l,int r){
        if(i==s.size()){
            if(l==0 && r==0) u.insert(temp);
            return ;
        }
        //check left side
        if(s[i]=='(' && l>0){
            f(s,temp,i+1,lcount,rcount,l-1,r);
        }
        //check right side
        if(s[i]==')' && r>0){
            f(s,temp,i+1,lcount,rcount,l,r-1);
        }

        temp.push_back(s[i]);
        if(s[i]!=')' && s[i]!='('){
            //random char for eg 'a'
            f(s,temp,i+1,lcount,rcount,l,r);
        }
        else if(s[i]=='('){
            f(s,temp,i+1,lcount+1,rcount,l,r);

        }
        else if(rcount<lcount){
            f(s,temp,i+1,lcount,rcount+1,l,r);
        }
        temp.pop_back();
        return ;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        vector<string> res;
        if(n==0) return res;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')   l++;
            else if(s[i]==')'){
                if(l==0) r++;
                else l--;
            }
        }
        string temp="";
        f(s,temp,0,0,0,l,r);
        while(u.size()>0){
            res.push_back(*u.begin());
            u.erase(*u.begin());
        }
        return res;
    }
};