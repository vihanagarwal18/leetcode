class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int ones=0;
        for(auto& p:s){
            if(p=='1') ones++;
        }
        int result=0;
        int zeroes=0;
        for(int i=0;i<n-1;i++){ //n-1 cause string can't be empty(left or right) 
            if(s[i]=='0') zeroes++;
            else if(ones>0) ones--;
            result=max(result,zeroes+ones);
        }
        return result;
    }
};