class Solution {
public:
    struct comp{
        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            if(a.second<b.second) return true;
            return false;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m; //number count
        for(auto& p:nums){
            m[p]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>> ,comp> q;
        for(auto& p:m){
            q.push(p);
        }
        vector<int> result;
        while(k>0){
            auto t=q.top();
            q.pop();
            result.push_back(t.first);
            k--;
        }
        return result;
    }
};