class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_set<int> u(candyType.begin(),candyType.end());
        int m=u.size();
        return min(n/2,m);
    }
};