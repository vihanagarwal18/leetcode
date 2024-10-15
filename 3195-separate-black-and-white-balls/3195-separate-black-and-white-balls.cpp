class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        int left=0;
        int right=n-1;
        while(right>=0 && s[right]=='1') right--;
        while(left<n && s[left]=='0') left++;
        long long result=0;
        long long count=0; //count of 1 
        long long countofzero=0;
        while(left<=right){
            while(left<=right && s[left]=='1'){
                left++;
                count++;
            }    
            while(left<=right && s[left]=='0'){
                left++;
                countofzero++;
            }        
            result+=(long long)countofzero*count;
            countofzero=0;
        }
        return result;
    }
};