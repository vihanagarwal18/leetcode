class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        int n = s.size();
        stack<string> st;
        while (i<n) {
            if (isdigit(s[i])) {
                string num = "";
                while (isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                st.push(num);
            } else if (s[i] == '[') {
                st.push("[");
                i++;
            } else if (s[i] == ']') {
                string temp = "";
                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();  // Popping '['
                string countstr = st.top();
                st.pop();
                int count = stoi(countstr);
                string temp2 = "";
                for (int j=0;j<count;j++) {
                    temp2 += temp;
                }
                st.push(temp2);
                i++;
            } else {
                st.push(string(1, s[i]));
                i++;
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
