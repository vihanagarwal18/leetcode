class Solution {
public:
    string compressedString(string word) {
        string res= "";
        int count=1;
        int i=0;
        int n=word.size();
        while (i<n) {
            while(word[i]==word[i+1]){
                if(count==9){
                    res+=to_string(count);
                    res+=word[i];
                    count=0;
                }
                count++;
                i++;
            }
            res+= to_string(count);
            res+= word[i];
            count=1;
            i++;
        }
        return res;
    }
};