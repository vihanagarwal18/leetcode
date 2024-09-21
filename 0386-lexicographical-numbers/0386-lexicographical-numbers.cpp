class Solution {
public:
    void rec(string &s, int n, char last,vector<int>& result){
        if (s.size() > 0 && s[0] == '0') return;
        int now = 0;
        if (s.size() > 0) now = stoi(s);
        if (now >= 1 && now <= n){
            result.push_back(now);
        }
        if (now > n) return;
        for (char i = '0'; i <= '9'; i++){
            s += i;
            rec(s, n, i,result);
            s.pop_back();
        }
    }

    vector<int> lexicalOrder(int n) {
        string s = "";
        vector<int> result;
        rec(s, n, '0',result);
        return result;
    }
};