class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())  return false;
        map<char,int> m1;
        map<char,int> m2;
        for(auto& p:word1){
            m1[p]++;
        }
        for(auto& p:word2){
            m2[p]++;
        }
        if(m1==m2) return true;
        unordered_set<char> u1(word1.begin(),word1.end());
        unordered_set<char> u2(word2.begin(),word2.end());
        multiset<int> s1;
        multiset<int> s2;
        for(auto& p:m1){
            s1.insert(p.second);
        }
        for(auto& p:m2){
            s2.insert(p.second);
        }
        if(u1==u2 && s1==s2) return true;
        return false;
    }
};