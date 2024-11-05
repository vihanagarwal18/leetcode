class Solution {
public:
    int minChanges(string s) {
        int result=0;
        string str1="00";
        string str2="11";
        int n=s.size();
        for(int i=0;i<n;i+=2){
            string temp=s.substr(i,2);
            if(temp!=str1 && temp!=str2) result++;
        }
        return result;
    }
};