class Solution {
public:
    int getLucky(string s, int k) {
        string convert = "";
        for (auto& p : s) {
            convert += to_string(p - 'a' + 1); 
        }
        while (k>0) {
            int sum = 0;
            for (char& c : convert) {
                sum+=c-'0'; 
            }
            convert = to_string(sum);
            k--;
        }
        return stoi(convert); 
    }
};
