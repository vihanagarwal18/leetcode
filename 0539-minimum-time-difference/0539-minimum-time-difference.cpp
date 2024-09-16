class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        priority_queue<int, vector<int>, greater<>> q;
        for (auto& p : timePoints) {
            string hour = p.substr(0, 2);
            string minutes = p.substr(3, 2);
            int temp = stoi(hour) * 60;
            temp += stoi(minutes);
            q.push(temp);
        }
        if (timePoints.size() > 1440) return 0; // duplicate time are there
        
        int first = q.top(); 
        int prev = first; 
        q.pop();
        int result = INT_MAX;
        while (!q.empty()) {
            int curr = q.top();
            q.pop();
            result = min(result, curr - prev);
            prev = curr;
        }
        result = min(result, 1440-(prev-first)); //for circular check
        return result;
    }
};
