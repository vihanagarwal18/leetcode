class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp=start^goal;
        int result=0;
        while(temp>0){
            if(temp%2==1) result++;
            temp=temp/2;
        }
        return result;
    }
};