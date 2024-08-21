class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string second=strs.back();
        int length=0;
        while(length<first.size()){
            if( first[length]!=second[length]) break;
            length++;
        }
        return first.substr(0,length);
    }
};