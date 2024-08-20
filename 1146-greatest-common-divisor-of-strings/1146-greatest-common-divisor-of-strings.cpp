class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string prefix="";
        string result="";
        int index=0;
        int n=str1.size();
        int m=str2.size();
        for(int i=0;i<n;i++){
            prefix+=str1[i];
            int l=prefix.size();
            if(l>m) break;
            string temp1="";
            string temp2="";
            //m/prefix.size() * prefix if this equal to str2 then new result has been found
            for(int j=0;j<m/l;j++){
                temp1+=prefix;
            }
            for(int j=0;j<n/l;j++){
                temp2+=prefix;
            }
            if(temp1==str2 && temp2==str1) result=prefix;
        }
        return result;
    }
};