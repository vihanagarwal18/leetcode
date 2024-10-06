class Solution {
public:
    vector<string> splitWords(const string& sentence) {
        vector<string> words;
        string word="";
        for (char c:sentence) {
            if (c==' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word="";
                }
            } 
            else word += c;
        }
        if (!word.empty()) words.push_back(word);
        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = splitWords(sentence1);
        vector<string> words2 = splitWords(sentence2);
        if (words1.size()<words2.size()) swap(words1, words2); //word1 will be longer
        int start=0; 
        int end=0;
        int n1=words1.size();
        int n2=words2.size();
        while (start<n2 && words1[start]==words2[start]) start++;
        while (end<n2 && words1[n1-end-1]==words2[n2-end-1]) end++;
        if(start+end>=n2) return true;
        return false;
    }
};
//below code was not working for test cases where there are extra letter inside a word only like luky and luccky it should return false
//but below code will return true
/*
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n=sentence1.size();
        int m=sentence2.size();
        string prefix="";
        string suffix="";
        for(int i=0;i<min(n,m);i++){
            if(sentence1[i]!=sentence2[i]) break;
            prefix+=sentence1[i];
        }
        for(int i=0;i<min(n,m);i++){
            if(sentence1[n-1-i]!=sentence2[m-1-i]) break;
            suffix+=sentence1[n-1-i];
        }
        //we have to reverse suffix also 
        reverse(suffix.begin(),suffix.end());
        if(suffix[0]==' ') suffix=suffix.substr(1,suffix.size()-1);
        cout<<prefix<<endl;
        cout<<suffix<<endl;
        cout<<"#"<<prefix+suffix<<"#"<<endl;
        if(prefix+suffix==sentence1 ||prefix+suffix==sentence2) return true;
        return false;
    }
};
*/