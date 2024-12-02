class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        int left=0;
        int result=1;
        for(int i=0;i<n;i++){
            if(sentence[i]==' ') {
                left=i+1;
                result++;
            }
            if(sentence.substr(left,i-left+1)==searchWord) return result;
        }
        return -1;
    }
};