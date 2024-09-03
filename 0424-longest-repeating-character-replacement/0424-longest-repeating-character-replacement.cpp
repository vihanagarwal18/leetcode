class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq=0;
        int ans=0;
        int j=0;
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'A']++;
            maxfreq=max(maxfreq,freq[s[i]-'A']);
            if(i-j+1-maxfreq>k && j<i){
                freq[s[j]-'A']--;
                j++;      
            }
           if(i-j+1-maxfreq<=k) ans=max(ans,i-j+1);
        }
        return ans;
    }
};