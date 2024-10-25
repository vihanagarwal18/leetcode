class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        sort(folder.begin(),folder.end());
        unordered_set<string> u;
        vector<string> result;
        result.push_back(folder[0]);
        u.insert(folder[0]);
        for(int i=1;i<n;i++){
            string t=folder[i];
            // bool flag=true;
            int j=1;
            string str="/";
            while(j<t.size()){
                while(j<t.size() && t[j]!='/'){
                    str+=t[j];
                    j++;
                }
                if(u.find(str)!=u.end()) break;
                if(j>=t.size()) {
                    u.insert(t);
                    result.push_back(t);
                }
                str+='/';
                j++;
            }
        }
        return result;
    }
};