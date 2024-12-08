class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int result=0;
        vector<int> maxsuffix(n);
        int maxx=0;
        for(int i=n-1;i>=0;i--){
            maxx=max(maxx,events[i][2]);
            maxsuffix[i]=maxx;
        }
        for(int i=0;i<n;i++){
            result=max(result,events[i][2]);
            int left=i+1;
            int right=n-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(events[mid][0]>events[i][1]){
                    result=max(result,events[i][2]+maxsuffix[mid]);
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
        }
        return result;
    }
};

/*
class Solution {
public:
    int solve(int index,vector<vector<int>>& events,vector<vector<int>>& memo,int picks,int lastend){
        if(index==events.size() || picks==2) return 0;
        if(memo[index][picks]!=-1) return memo[index][picks];

        //take 
        int take=0;
        if(events[index][0]>lastend){
            take=events[index][2]+solve(index+1,events,memo,picks+1,events[index][1]);
        }
        int nottake=solve(index+1,events,memo,picks,lastend);
        memo[index][picks]=max(take,nottake);
        return memo[index][picks];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>  memo(n,vector<int>(3,-1));
        return solve(0,events,memo,0,-1);
    }
};
*/