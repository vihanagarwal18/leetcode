class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto& p:s) m[p]++;
        vector<pair<int,char>> vect;
        for(auto& p:m){
            vect.push_back({p.second,p.first});
        }
        sort(vect.begin(),vect.end());
        string result="";
        for(auto& p:vect){
            for(int i=0;i<p.first;i++) result+=p.second;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};