class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int result=INT_MAX;
        for(auto&p:letters){
            if(p>target && p-target<result){
                result=p-target;
            }
        }
        if(result==INT_MAX) return letters[0];
        return result+target;
    }
};