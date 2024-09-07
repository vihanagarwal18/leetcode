class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<long long> net(n);
        int total = 0, curr = 0, maxindex = 0;
        for (int i = 0; i < n; i++) {
            net[i] = gas[i] - cost[i];
            total += net[i];
            curr += net[i];
            if (curr < 0) {
                maxindex = i + 1;
                curr = 0;
            }
        }
        if(total>=0) return maxindex;
        return -1;
    }
};
