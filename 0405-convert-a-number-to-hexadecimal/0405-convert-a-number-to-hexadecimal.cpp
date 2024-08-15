class Solution {
public:
    string toHex(int num) {
        unsigned int n=num;
        if(n==0) return "0";
        vector<char> str={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string result="";
        while(n>0){
            int temp=n%16;
            n=n/16;
            result+=str[temp];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};