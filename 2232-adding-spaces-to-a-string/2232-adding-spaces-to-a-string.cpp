class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=spaces.size();
        string result="";
        int m=s.size();
        int buffer=0;
        int index=0; //of spaces
        int idx=0; // of string
        while(idx<m){
            if( index<n && spaces[index]<=idx) {
                result+=" ";
                index++;
            }
            else{
                result+=s[idx];
                idx++;
            }
        }
        return result;
        // int buffer=0;
        // for(auto& p:spaces){
        //     s.insert(p+buffer," ");
        //     buffer++;
        // }
        // return s;
    }
};