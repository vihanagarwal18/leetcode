class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        unordered_set<char> u;
        for(auto& p:s){
            m1[p]++;
            u.insert(p);
        }
        for(auto& p:t){
            m2[p]++;
            u.insert(p);
        }
        int diff=0;
        while(u.size()>0){
            auto c=*u.begin();
            u.erase(c);
            diff+=abs(m1[c]-m2[c]);
        }
        return diff/2;
    }
};