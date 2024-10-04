class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long result = 0;
        int n = skill.size();
        if (n%2 == 1) return -1;
        if (n == 2) return (long long)skill[0] * skill[1];
        long long total = 0;
        unordered_map<int, int> m;
        for (auto& p : skill) {
            total += p;
            m[p]++;
        }
        if (total%(n/2) != 0) return -1;
        long long sum = total / (n/2);

        for (auto& p : m) {
            while (p.second > 0) {
                long long first = p.first;
                long long second = sum - first;
                if (m[second] == 0) return -1;
                m[second]--;
                result += first * second;
                p.second--;
            }
        }
        
        return result;
    }
};
