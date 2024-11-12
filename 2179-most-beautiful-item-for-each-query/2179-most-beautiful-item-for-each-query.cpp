class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> result;
        map<int, int> m;
        for (auto& p : items) {
            m[p[0]] = max(m[p[0]], p[1]);
        }
        int maxbeauty = 0;
        map<int,int> res;
        for (auto& p : m) {
            maxbeauty = max(maxbeauty, p.second);
            res[p.first] = maxbeauty;
        }
        for (auto& q : queries) {
            auto it = res.upper_bound(q); //will find value which is next bigger than q in res 
            if (it == res.begin()) {
                result.push_back(0);
            } 
            else {
                it--;
                result.push_back(it->second);
            }
        }     
        return result;
    }
};
