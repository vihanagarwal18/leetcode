class Solution {
public:
    string makeFancyString(string s) {
        string result=s.substr(0,2);
        char last=s[1];
        char secondlast=s[0];
        for(int i=2;i<s.size();i++){
            if(s[i]==last && last==secondlast) continue;
            result+=s[i];
            secondlast=last;
            last=s[i];
        }
        return result;
    }
};