class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> result(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first< temperatures[i]){
                auto t=st.top();
                int idx=t.second;
                result[idx]+=i-idx;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
        return result;
    }
};