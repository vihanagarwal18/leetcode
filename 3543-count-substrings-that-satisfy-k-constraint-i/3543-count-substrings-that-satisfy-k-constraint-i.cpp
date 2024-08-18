class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int result=0;
        int countzero=0;
        int countone=0;
        int i=0;
        int left=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') countzero++;
            if(s[i]=='1') countone++;
            while(countzero>k && countone>k){
                if(s[left]=='1') countone--;
                if(s[left]=='0') countzero--;
                left++;
            }
            result+=i-left+1;
        }
        return result;
    }
};