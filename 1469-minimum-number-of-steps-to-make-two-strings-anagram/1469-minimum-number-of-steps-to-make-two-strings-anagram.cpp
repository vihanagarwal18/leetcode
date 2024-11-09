class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26,0);
        for(auto& p:s) count[p-'a']++;
        for(auto& p:t) count[p-'a']--;
        int diff=0;
        for(int i=0;i<26;i++) diff+=abs(count[i]);
        return diff/2;
    }
};