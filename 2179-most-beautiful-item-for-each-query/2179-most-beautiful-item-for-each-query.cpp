class Solution {
public:
    bool static comp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    int binarysearch(vector<vector<int>>& items,int q){
        int maxbeauty=0;
        int left=0;
        int right=items.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(items[mid][0]>q){
                right=mid-1;
            }
            else{
                maxbeauty=max(maxbeauty,items[mid][1]);
                left=mid+1;
            }
        }
        return maxbeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        vector<int> result(n);
        sort(items.begin(),items.end(),comp); //smaller price first
        int maxx=0;
        for(int i=0;i<items.size();i++){
            maxx=max(maxx,items[i][1]);
            items[i][1]=maxx;
        }
        for(int i=0;i<n;i++){
            result[i]=binarysearch(items,queries[i]);
        }
        return result;
    }

};