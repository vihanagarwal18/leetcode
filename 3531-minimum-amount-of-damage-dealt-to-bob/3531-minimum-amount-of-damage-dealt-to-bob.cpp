class Solution {
public:
    bool static comp(const pair<double, int>& a, const pair<double, int>& b) {
        return a.first > b.first;
    }

    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<int> time_to_kill(n);
        for (int i = 0; i < n; i++) {
            time_to_kill[i] = (health[i] + power - 1) / power; // Equivalent to ceil(health[i] / power)
            //6 ko marne main 2 time lagega 4 ki power se toh uske liye
        }

        vector<pair<double, int>> ratio(n);
        for (int i = 0; i < n; i++) {
            ratio[i] = {(double)(damage[i]) / time_to_kill[i], i};
        }

        sort(ratio.begin(), ratio.end(), comp); // Sorted according to the ratio, higher ratio first

        long long total_damage = 0;
        long long current_damage = 0;
        for (int& dmg : damage) {
            current_damage += dmg;
        }

        for (auto& p : ratio) {
            int index = p.second;
            total_damage += current_damage * time_to_kill[index];
            current_damage -= damage[index];
        }

        return total_damage;
    }
};
