class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int left=0;
        while(left<n-1 && arr[left]<=arr[left+1]) left++;
        if(left==n-1) return 0; //already sorted in ascending
        int right=n-1;
        while(right>0 && arr[right]>=arr[right-1]) right--;
        int result=min(n-left-1,right);//ya toh right ke left ki puri hata doh ya left ke right ki puri hata doh
        int i=0;
        int j=right;
        while(i<=left && j<n){
            if(arr[i]<=arr[j]){
                result=min(j-i-1,result);
                i++;
            }
            else j++;
        }
        return result;


    }
};