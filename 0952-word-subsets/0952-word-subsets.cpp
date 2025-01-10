class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> countchar(26,0);
        for(auto& p:words2){
            vector<int> count(26,0);
            for(auto& q:p){
                count[q-'a']++;
                if(count[q-'a']>countchar[q-'a']) countchar[q-'a']=count[q-'a'];
            }
        }
        vector<string> result;
        vector<int> empty(26,0);
        for(auto& p:words1){
            vector<int> temp=countchar;
            vector<int> count(26,0);
            for(auto& q:p) count[q-'a']++;
            bool flag=true;
            for(int i=0;i<26;i++){
                if(count[i]-countchar[i]<0){
                    flag=false;
                    break;
                }
            }
            if(flag) result.push_back(p);
        }
        return result;
    }
};