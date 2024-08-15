class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto& p:nums){
            m[p]++;
        }
        int pair=0;
        int leftover=0;
        for(auto& p:m){
            int count=p.second;
            pair+=count/2;
            leftover+=count%2;
        }
        return {pair,leftover};
    }
};