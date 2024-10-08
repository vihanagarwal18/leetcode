class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int count=0;
        int open=0;
        int close=0;
        int right=n-1;
        for(int i=0;i<n;i++){
            if(s[i]=='[') open++;
            else{
                close++;
                if(close>open){
                    while(right>0 && s[i]!='['){
                        right--;
                    }
                    s[i]='[';
                    s[right]=']';
                    open++;
                    close--;
                    count++;
                }
            }
        }
        return count;
    }
};