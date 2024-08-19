class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result="";
        int n=word1.size();
        int m=word2.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            result+=word1[i];
            result+=word2[j];
            i++;
            j++;
        }
        while(i<n){
            result+=word1[i];
            i++;
        }
        while(j<m){
            result+=word2[j];
            j++;
        }
        return result;
    }
};