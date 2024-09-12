class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result=0;
        unordered_set<char> allow(allowed.begin(),allowed.end());
        for(auto& p:words){
            bool flag=true;
            for(auto& q:p){
                if(allow.find(q)==allow.end()) {
                    flag=false;
                    break;
                }
            }
            result+=(flag==true);
        }
        return result;
    }
};