class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u1(nums1.begin(),nums1.end());
        unordered_set<int> u2(nums2.begin(),nums2.end());
        vector<vector<int>> result;
    
        //in list1 but not in list2
        vector<int> temp;
        for(auto& p:u1){
            if(u2.find(p)==u2.end()) temp.push_back(p); 
        }
        result.push_back(temp);
        //in list2 but not in list1
        vector<int> temp2;
        for(auto& p:u2){
            if(u1.find(p)==u1.end()) temp2.push_back(p); 
        }
        result.push_back(temp2);
        return result;
    }
};