class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> u1;
        unordered_set<string> u2;
        int n=arr1.size();
        int m=arr2.size();
        int result=0;
        for(auto& num:arr1){
            string p=to_string(num);
            for(int i=0;i<p.size();i++){
                u1.insert(p.substr(0,i+1));
            }
        }
        for(auto& num:arr2){
            string p=to_string(num);
            int length=0;
            for(int i=0;i<p.size();i++){
                string temp=p.substr(0,i+1);
                if(u1.find(temp)==u1.end()){
                    break;
                }
                length++;
            }
            result=max(result,length);
        }
        return result;

    }
};