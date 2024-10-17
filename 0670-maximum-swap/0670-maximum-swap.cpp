class Solution {
public:
    int maximumSwap(int num) {
        string number="";
        int temp=num;
        while(temp>0){
            number=to_string(temp%10)+number;
            temp=temp/10;
        }
        int n=number.size();
        int result=num;
        for(int i=0;i<n-1;i++){
            int right=i+1;
            for(int j=right;j<n;j++){
                if(number[j]>number[i]){
                    // string tem=number;
                    swap(number[i],number[j]);
                    result=max(result,stoi(number));
                    swap(number[i],number[j]);
                }
            }
        }
        return result;
    }
};