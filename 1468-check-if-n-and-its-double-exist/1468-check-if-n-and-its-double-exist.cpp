class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>  u;
        int countofzero=0;
        for(auto& p:arr){
            if(p==0) countofzero++;
            u.insert(p);
        }
        if(countofzero>1) return true;
        for(auto& p:arr){
            if(p!=0 && u.find(p*2)!=u.end()) return true;
        }
        return false;
    }
};