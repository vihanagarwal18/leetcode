class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        for(int i=n-1;i>=0;i--){
            digits[i]+=carry;
            carry=0;
            if(digits[i]==10){
                carry=1;
                digits[i]=0;
            }
            if(i==0 && carry==1) digits.insert(digits.begin(),1);
        }
        return digits;
    }
};