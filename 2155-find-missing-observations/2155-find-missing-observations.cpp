class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = 0;
        for (auto& p : rolls) {
            total += p;
        }
        int actualTotal = mean * (n + m);
        int sumOfN = actualTotal - total;
        if (sumOfN < n || sumOfN > 6 * n) return {};

        vector<int> result(n, 1); 
        sumOfN -= n; 
        int i = 0;
        while (sumOfN > 0) {
            result[i]++;
            sumOfN--;
            if (result[i] > 6) return {}; 
            i = (i + 1) % n; 
        }
        return result;
    }
};
