class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string,vector<int>> m;
        vector<int> result=ways(expression,m);
        return result;
    }
    vector<int> ways(string s,unordered_map<string,vector<int>>& m){
        if(m.find(s)!=m.end()) return m[s];
        vector<int> result;
        for(int i=0;i<s.size();i++){
            if(ispunct(s[i])){
                //if it is a operator 
                vector<int> left=ways(s.substr(0,i),m);
                vector<int> right=ways(s.substr(i+1),m);
                for(auto& a:left){
                    for(auto& b:right){
                        if(s[i]=='+'){
                            result.push_back(a+b);
                        }
                        else if(s[i]=='-'){
                            result.push_back(a-b);
                        }
                        else if(s[i]=='*'){
                            result.push_back(a*b);
                        }
                    }
                }
            }
        }
        if(result.empty()){ //if there are no operator only number
            result.push_back(stoi(s));
        }
        m[s]=result;
        return result;
    }
};