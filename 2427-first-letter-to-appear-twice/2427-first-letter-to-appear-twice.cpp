class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> u;
        for(auto& p:s){
            if(u.find(p)!=u.end()) return p;
            u.insert(p);
        }
        return 'a';
    }
};