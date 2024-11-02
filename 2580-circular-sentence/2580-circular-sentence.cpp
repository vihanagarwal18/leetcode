class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();
        vector<string> word;
        string str="";
        for(int i=0;i<n;i++){
            if(sentence[i]==' '){
                word.push_back(str);
                str="";
            }
            else str+=sentence[i];
        }
        word.push_back(str);
        if(word.size()==1 && word[0][0]!=word[0][word[0].size()-1]) return false;
        for(int i=1;i<word.size();i++){
            char first=word[i-1][word[i-1].size()-1];
            char second=word[i][0];
            if(first!= second) return false;
        }
        if(word[0][0]!=word[word.size()-1][word[word.size()-1].size()-1]) return false;
        return true;
    }
};