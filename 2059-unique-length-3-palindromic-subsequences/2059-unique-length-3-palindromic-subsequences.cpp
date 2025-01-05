class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_set<char> u;
        int result=0;
        for(auto& p:s) u.insert(p);
        for(auto& p:u){
            int i=-1;
            int j=0;
            for(int k=0;k<n;k++){
                if(s[k]==p){
                    if(i==-1) i=k;
                    j=k;
                }
            }
            //i is first occurence and j is last occurence
            unordered_set<char> u2;
            for(int k=i+1;k<j;k++) u2.insert(s[k]);
            result+=u2.size();
        }
        return result;
    }
};