class Solution {
public:
    string invert(string& s){
        string temp="";
        for(auto& p:s){
            if(p=='0') temp+='1';
            else temp+='0';
        }
        return temp;
    }
    char findKthBit(int n, int k) {
        if(k==0 || n==0) return '0';
        string s="0";
        for(int i=0;i<n-1;i++){
            string x=invert(s);
            reverse(x.begin(),x.end());
            s=s+"1"+x;
        }
        return s[k-1];
    }
};