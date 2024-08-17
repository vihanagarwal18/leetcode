class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int result=0;
        // if(target<=startValue){
        //     return abs(target-startValue);
        // }
        while(target!=startValue){
            if(target>startValue && target%2==0){
                target=target/2;
            }
            else{
                target++;
            }
            result++;
        }
        return result;
    }
};