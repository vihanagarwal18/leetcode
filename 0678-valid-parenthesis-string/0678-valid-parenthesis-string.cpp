class Solution {
public:
    bool checkValidString(string s) {
        int countmax=0;
        int countmin=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                countmax++;
                countmin++;
            }
            else if(s[i]==')') {
                countmax--;
                countmin--;
            }
            else {
                countmax++;
                countmin--;
            }
            if(countmin<0) countmin=0;
            if(countmax<0) return false;
        }
        if(countmin==0) return true;
        return false;
    }
};