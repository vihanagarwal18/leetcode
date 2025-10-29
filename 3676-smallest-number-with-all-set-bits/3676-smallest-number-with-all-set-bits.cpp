class Solution {
public:
    int smallestNumber(int n) {
        int power=1;
        while(pow(2, power)<=n){
            power++;
        }
        return pow(2, power)-1;
    }
};