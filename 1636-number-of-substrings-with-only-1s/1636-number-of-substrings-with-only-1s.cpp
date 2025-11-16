class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1000000007;
        long long result = 0;
        long long count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                result = (result + (count + 1) * count / 2) % MOD;
                count = 0;
            } else {
                count++;
            }
        }
        if (count > 0) {
            result = (result + (count + 1) * count / 2) % MOD;
        }

        return result;
    }
};
