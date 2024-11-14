class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        vector<int> lastindex(26,0);
        int n=s.size();
        for (int i=0;i<n;i++) {
            lastindex[s[i]-'a']=i;
        }
        int start=0;
        int end=0;
        for (int i=0; i<n;i++) {
            end=max(end,lastindex[s[i]-'a']);
            if (i==end) {
                result.push_back(end-start+1);
                start=i+1;
            }
        }
        return result;
    }
};
