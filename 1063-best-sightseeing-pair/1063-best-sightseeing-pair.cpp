class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int result=-1;
        int current=values[0];
        for(int i=1;i<n;i++){
            result=max(result,values[i]-i+current);
            if(values[i]+i>current) current=values[i]+i;
        }   
        return result;
    }
};