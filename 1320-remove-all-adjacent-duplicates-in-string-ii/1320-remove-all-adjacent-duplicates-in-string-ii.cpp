class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],1});
            }
            else if(st.top().first==s[i] && st.top().second<k-1){
                int count=st.top().second;
                st.pop();
                st.push({s[i],count+1});
            }
            else st.pop();
        }
        string result="";
        while(st.size()>0){
            for(int i=0;i<st.top().second;i++){
                result+=st.top().first;
            }
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};