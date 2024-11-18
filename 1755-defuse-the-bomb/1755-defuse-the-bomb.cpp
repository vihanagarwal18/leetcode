class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> result(n,0);
        if(k==0)    return result;
        int sum=0;
        if(k>0){
            for(int i=1;i<=k;i++)   sum+=code[i%n];
            for(int i=0;i<n;i++){
                result[i]=sum;
                sum += code[(i+k+1)%n]-code[(i+1)%n];
            }
            return result;
        }
        //k<0
        k=abs(k);
        for(int i=1;i<=k;i++){
            sum+=code[(n-i)%n];
        }
        for(int i=0;i<n;i++){
            result[i]=sum;
            sum+=code[i%n]-code[(n-k+i)%n];
        }
        return result;
    }
};