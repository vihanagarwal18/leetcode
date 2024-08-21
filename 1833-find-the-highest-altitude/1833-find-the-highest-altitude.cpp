class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxpoint=0;
        int point=0;
        for(auto& p:gain){
            point+=p;
            maxpoint=max(maxpoint,point);
        }
        return maxpoint;
    }
};