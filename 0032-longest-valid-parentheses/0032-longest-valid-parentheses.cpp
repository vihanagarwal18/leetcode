class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int> st;
        st.push(-1); //when st is empty
        int maxlength=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    //new base is needed as this closing bracket was wrong
                    st.push(i);
                }
                else{
                    maxlength=max(maxlength,i-st.top());
                }
            }
        }
        return maxlength;
    }
};