class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        if(str1+str2!=str2+str1) return "";
        int g=gcd(m,n); //length of prefix which will divide both
        string result=str1.substr(0,g);
        return result;
    }
};