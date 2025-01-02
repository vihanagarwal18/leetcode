class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> prefix(n);
        int count=0;
        unordered_set<char> u;
        u.insert('a');
        u.insert('e');
        u.insert('i');
        u.insert('o');
        u.insert('u');
        for(int i=0;i<n;i++){
            int m=words[i].size();
            if(u.find(words[i][0])!=u.end() && u.find(words[i][m-1])!=u.end()) count++;
            prefix[i]=count;
        }
        vector<int> result;
        for(auto& p:queries){
            if(p[0]==0){
                result.push_back(prefix[p[1]]);
            }
            else{
                result.push_back(prefix[p[1]]-prefix[p[0]-1]);
            }
        }
        return result;
    }
};