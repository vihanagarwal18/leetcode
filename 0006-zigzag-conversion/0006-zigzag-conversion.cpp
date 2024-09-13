class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        vector<string> v(numRows, "");
        int j=0;
        int i=0;
        if(numRows >= n || numRows == 1) return s;
        while(i < n){
            while(j < numRows && i < n){
                v[j] += s[i];
                i++;
                j++;
            }
            j = j-2; //j range se bhar gya tha and humei 2nd last row se chalu karna
            while(j > 0 && i < n){
                v[j] += s[i];
                i++;
                j--;
            }
        }
        string res;
        for(auto &it : v) res += it; 
        return res;
    }
};