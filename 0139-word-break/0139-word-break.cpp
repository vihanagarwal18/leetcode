class Solution {
public:
    bool solve(int index,int& n,vector<int>& memo,string s, unordered_set<string>& wordset){
        if(index>=n) return true;
        if(memo[index]!=-1) return memo[index];

        for(int i=index;i<n;i++){
            string newstring=s.substr(index,i-index+1);
            if(wordset.find(newstring)!=wordset.end() && solve(i+1,n,memo,s,wordset)){
                return memo[index]=true;
                
            }
        }
        return memo[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> memo(n,-1);
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        return solve(0,n,memo,s,wordset);
        // memo[0]=1;
        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<=i;j++){
        //         if(memo[j]==1){
        //             string temp=s.substr(j,i-j+1);
        //             if(wordset.find(temp)!=wordset.end()){
        //                 //word exist
        //                 memo[i]=1;
        //             }
        //         }
        //     }
        // }
        // return memo[n];
    }
};