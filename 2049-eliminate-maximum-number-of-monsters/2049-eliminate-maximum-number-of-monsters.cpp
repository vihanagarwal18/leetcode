class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        priority_queue<double, vector<double>, greater<>> pq;
        
        for (int i = 0; i < n; i++) {
            pq.push((double)dist[i] / speed[i]); // only store time
        }

        int time = 1;
        int result = 1;
        pq.pop(); // first monster would be killed at the start
        
        while (!pq.empty()) {
            double monsterTime = pq.top();
            if (monsterTime > time) {
                time++;
                pq.pop();
                result++;
            } else {
                return result;
            }
        }
        return result;
    }
};
