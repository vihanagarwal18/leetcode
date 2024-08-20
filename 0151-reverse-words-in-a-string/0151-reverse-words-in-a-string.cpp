class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int left = 0;
        int n = s.size();
        while (left < n) {
            while (left<n && s[left]==' ') left++;
            int right = left;
            while (right<n && s[right] != ' ') right++;
            if (left < right) words.push_back(s.substr(left, right - left));
            left = right;
        }
        string result = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i != 0) result += " ";
        }
        return result;
    }
};
