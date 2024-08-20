class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxx=*max_element(candies.begin(),candies.end());
        vector<bool> result;
        for(auto& p:candies){
            if(p+extraCandies>=maxx) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};