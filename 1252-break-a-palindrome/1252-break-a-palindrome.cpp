class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1) return "";
        string allA(n,'a');
        // if(allA==palindrome){
        //     //change last character to b
        //     string temp(n-1,'a');
        //     temp+='b';
        //     return temp;
        // }
        int countA=0;
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                break;
            }
            else{
                countA++;
            }
        }
        if(countA==n/2) {
            //either all 'a' are there or "aba" is the string
            palindrome[n-1]='b';
        }
        return palindrome;
    }
};