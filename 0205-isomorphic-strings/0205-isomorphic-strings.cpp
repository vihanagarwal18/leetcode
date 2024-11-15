class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        map<int,int> ms;
        map<int,int> mt;
        // cout<<(int)ms['a'];
        for(int i=0;i<n;i++){
            int ss=(int)s[i];
            int tt=(int)t[i];
            if(ms[ss]!=0 || mt[tt]!=0){
                if(ms[ss]!=tt || mt[tt]!=ss) return false;
            }
            else{
                ms[ss]=tt;
                mt[tt]=ss;
            }
        }
        return true;
    }
};