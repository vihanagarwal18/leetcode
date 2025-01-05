class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> count(n+1,0);
        for (auto& p : shifts) {
            if (p[2] == 1) {
                count[p[0]]++;
                count[p[1] + 1]--;
            } else {
                count[p[0]]--;
                count[p[1] + 1]++;
            }
        }
        // vector<int> prefix(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=count[i];
            s[i]=((s[i]-'a'+sum)%26+26)%26 +'a';
        }
        return s;
    }
};