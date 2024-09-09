class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u1(nums1.begin(),nums1.end());
        unordered_set<int> u2(nums2.begin(),nums2.end());
        vector<int> res;
        for(auto& p:u2){
            if(u1.find(p)!=u1.end()){
                res.push_back(p);
            }
        }
        return res;
    }
};