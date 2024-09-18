class comp {
public:
    bool operator()(const string& a, const string& b) {
        if(a+b<b+a) return true;
        return false;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<string,vector<string>,comp> pq;
        string result="";
        for(auto& p:nums){
            pq.push(to_string(p));
        }
        while(pq.size()>0){
            auto t=pq.top();
            pq.pop();
            result+=t;
        }
        if(result[0]=='0') return "0";
        return result;
    }
};