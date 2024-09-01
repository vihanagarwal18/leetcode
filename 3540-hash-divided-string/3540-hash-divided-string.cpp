class Solution {
public:
    string stringHash(string s, int k) {
        string result="";
        int n=s.size();
        int t=n/k;
        for(int i=0;i<n;i=i+k){
            int sum=0;
            for(int j=0;j<k;j++){
                sum=(sum+(s[j+i]-'a'))%26;
            }
            char c='a';
            c+=sum;
            result+=c;
        }
        return result;
    }
};