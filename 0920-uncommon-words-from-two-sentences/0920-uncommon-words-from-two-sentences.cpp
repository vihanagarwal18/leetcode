class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> m;
        int n = s1.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] == ' ') {
                string temp = s1.substr(j, i - j);
                m[temp]++;
                j = i + 1;
            }
        }
        if (j < n) {
            string temp = s1.substr(j, n - j);
            m[temp]++;
        }
        j = 0;
        n = s2.size();
        for (int i = 0; i < n; i++) {
            if (s2[i] == ' ') {
                string temp = s2.substr(j, i - j);
                m[temp]++;
                j = i + 1;
            }
        }
        if (j < n) {
            string temp = s2.substr(j, n - j);
            m[temp]++;
        }
        vector<string> result;
        for (auto& p : m) {
            if (p.second == 1) {
                result.push_back(p.first);
            }
        }
        return result;
    }
};
