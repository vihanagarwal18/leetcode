class comp {
public:
    bool operator()(const vector<double>& a, const vector<double>& b) {
        double gain_a = (a[0] + 1) / (a[1] + 1) - a[0] / a[1];
        double gain_b = (b[0] + 1) / (b[1] + 1) - b[0] / b[1];
        return gain_a < gain_b;
        //greater gain at top
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extrastudents) {
        int n = classes.size();
        priority_queue<vector<double>, vector<vector<double>>, comp> pq;
        
        for (const auto& c : classes) {
            pq.push({(double)c[0], (double)c[1]});
        }
        
        while (extrastudents > 0) {
            auto top = pq.top();
            pq.pop();
            double numerator = top[0], denominator = top[1];
            pq.push({numerator + 1, denominator + 1});
            extrastudents--;
        }
        
        double result = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            result += top[0] / top[1];
        }
        return result/n;
    }
};
