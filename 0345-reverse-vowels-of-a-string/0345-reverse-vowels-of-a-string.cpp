class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vowel;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vowel.push_back(i);
            }   
        }
        int left=0;
        int right=vowel.size()-1;
        string result=s;
        while(left<=right){
            swap(result[vowel[left]],result[vowel[right]]);
            right--;
            left++;
        }
        return result;
    }
};