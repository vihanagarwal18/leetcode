class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<long long> net(n);
        int total = 0;
        int current=0;
        int maxindex=0;
        for (int i = 0; i < n; i++) {
            total+=gas[i]-cost[i];
            current+=gas[i]-cost[i];
            if(current<0){
                current=0;
                maxindex=i+1;
            }
        }
        if(total>=0) return maxindex;
        return -1;
    }
};
