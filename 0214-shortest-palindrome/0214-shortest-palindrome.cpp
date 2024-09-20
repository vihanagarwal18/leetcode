class Solution {
public:
    string shortestPalindrome(string s) {
        int m=s.size();
        string rstr = s;
        reverse(rstr.begin(), rstr.end());
        string combined_str = s + '#' + rstr;
        int n = combined_str.size();
        vector<int> pattern(n, -1);
        int low = 0;
        int high = 1;
        //kmp
        //We want to know the longest prefix of the original string s that is also a suffix in the combined string (s + '#' + rstr).
        //This will help us identify the longest part of s that is already a palindrome
        while (high < n) {
            if (combined_str[low] == combined_str[high]) {
                pattern[high] = low;
                low++;
                high++;
            } 
            else if (low>0) {
                low=pattern[low-1]+1;
            } 
            else high++;
        }

        string temp= rstr.substr(0,m-pattern[n-1]-1)+s;//add non-palindrome part in front of the original string
        return temp;
    }
};