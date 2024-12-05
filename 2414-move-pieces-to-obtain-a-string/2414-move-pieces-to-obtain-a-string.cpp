class Solution {
public:
    bool canChange(string start, string target) {
        int i1=0;
        int i2=0;
        int n=start.size();
        int m=target.size();
        while(i1<n && i2<m){
            while(i1<n && start[i1]=='_') i1++;
            while(i2<m && target[i2]=='_') i2++;
            if(i1<n && i2<m){
                if(start[i1]!=target[i2]) return false;
                if(start[i1]=='L' && i1<i2) {
                    //means order was correct but this is not possible as number of character are less on start string
                    //for cases like where start is _L... and target is __L...
                    return false;
                }
                if(start[i1]=='R' && i1>i2) return false;
                i1++;
                i2++;
            }
        }
        while(i1<n){
            if(start[i1]!='_') return false;
            i1++;
        }
        while(i2<m){
            if(target[i2]!='_') return false;
            i2++;
        }
        return true;
    }
};