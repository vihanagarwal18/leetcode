class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> frequency(26,0);
        for(auto& p:s1){
            frequency[p-'a']++;
        }
        int n=s2.size();
        int m=s1.size();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s2[i]-'a']++;
            if(i-m+1<0) continue;
            if(i-m+1>0){
                freq[s2[i-m]-'a']--;
            }
            if(frequency==freq) return true;
        }
        return false;
    }
};