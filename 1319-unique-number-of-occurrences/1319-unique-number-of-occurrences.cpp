class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto& p:arr){
            m[p]++;
        }
        unordered_set<int> u;
        for(auto& p:m){
            if(u.find(p.second)!=u.end()) return false;
            u.insert(p.second);
        }
        return true;
    }
};