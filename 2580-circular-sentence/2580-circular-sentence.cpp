class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();
        for(int i=0;i<n;i++){
            if(sentence[i]==' '){
                if(sentence[i+1]!=sentence[i-1]) return false;
            }
        }
        if(sentence[n-1]!=sentence[0]) return false;
        return true;
    }
};