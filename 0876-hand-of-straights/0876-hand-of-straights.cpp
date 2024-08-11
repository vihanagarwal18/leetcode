class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        priority_queue<int, vector<int>, greater<int>> q(hand.begin(), hand.end());
        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        while (!q.empty()) {
            int first = q.top();
            q.pop();
            if (count[first] == 0) continue; //card use ho rakha
            for (int i=0;i<groupSize;i++) {
                int nextcard=first+i;
                if (count[nextcard]==0) return false; 
                count[nextcard]--;
            }
        }
        return true;
    }
};
