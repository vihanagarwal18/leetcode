class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;
        int i = 0;
        while (i < word.length()) {
            while (word[i] == word[i + 1]) {
                if (count == 9) {
                    comp += to_string(count);
                    comp += word[i];
                    count = 0;
                }
                count++;
                i++;
            }
            comp += to_string(count);
            comp += word[i];
            count = 1;
            i++;
        }
        return comp;
    }
};