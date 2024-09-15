class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        vector<int> firstOccurrence(32, -1); //2^5 is 32 so 32 different possibilities we have
        firstOccurrence[0] = 0;
        int bitmask = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') bitmask =bitmask^  (1 << 0);  //first bit pe xor 1 se
            else if (s[i] == 'e') bitmask =bitmask^ (1 << 1); //second bit pe xor 1 se
            else if (s[i] == 'i') bitmask =bitmask^ (1 << 2);
            else if (s[i] == 'o') bitmask =bitmask^ (1 << 3);
            else if (s[i] == 'u') bitmask =bitmask^ (1 << 4); // fifth but pe xor  1 se
            
            if (firstOccurrence[bitmask] != -1) {
                maxLength = max(maxLength, i + 1 - firstOccurrence[bitmask]);
            } 
            else{
                firstOccurrence[bitmask] = i + 1;
            }
        }
        
        return maxLength;
    }
};
