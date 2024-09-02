class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> u;
        for(auto& p:nums){
            if(u.find(p)!=u.end()) return p;
            u.insert(p);
        }
        return -1;
    }
};