class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> u(word.begin(),word.end());
        int result=0;
        for(auto& p:u){
            if(islower(p)){
                if(u.find(toupper(p))!=u.end()) result++;
            }
        }
        return result;
    }
};