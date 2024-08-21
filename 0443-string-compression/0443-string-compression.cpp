class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> result;
        int i=0;
        int n=chars.size();
        while(i<n){
            char letter=chars[i];
            int count=0;
            while(i<n && chars[i]==letter){
                i++;
                count++;
            }
            result.push_back(letter);
            if(count>1){
                string temp=to_string(count);
                result.insert(result.end(), temp.begin(),temp.end());
            }
        }
        chars=result;
        return chars.size();
    }
};