class Solution {
public:
    class comp{
        public:
            bool operator()(vector<int>& a,vector<int>&b){
                if(a[0]>b[0]) return true;
                return false;
            }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,comp> minheap;
        int maximum=INT_MIN;
        vector<int> index(n,0); 
        for(int i=0;i<n;i++){
            minheap.push({nums[i][0],i,1});
            maximum = max(maximum, nums[i][0]);
        }
        vector<int> result={minheap.top()[0],maximum};
        while(true){
            int minimum=minheap.top()[0];
            int index=minheap.top()[1];
            int arrindex=minheap.top()[2];
            minheap.pop();
            
            if(maximum-minimum<result[1]-result[0]){
                result[0]=minimum;
                result[1]=maximum;
            }
            if(arrindex>=nums[index].size()){
                break;
            }
            minheap.push({nums[index][arrindex],index,arrindex+1});
            maximum=max(maximum,nums[index][arrindex]);
        }
        return result;
    }
};