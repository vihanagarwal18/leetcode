class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        if (len == 1) {
            return to_string(stoi(n) - 1); 
        }
        vector<long long> candidates;
        candidates.push_back(pow(10,len-1)-1);  // Eg: 999 for 1000
        candidates.push_back(pow(10,len)+1);  // Eg: 10001 for 9999
        int mid=(len+1)/2;
        long long prefix = stoll(n.substr(0,mid));//left half

        // Prefix ko thoda adjust karke variations
        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string temp=string(p.rbegin()+(len%2),p.rend());
            string candidate = p + temp;  // Mirror karke palindrome banao
            candidates.push_back(stoll(candidate));
        }
        long long num = stoll(n);
        long long closest = -1;
        for (long long cand : candidates) {
            if (cand == num) continue; 
            if (closest==-1|| abs(cand-num)<abs(closest-num)||(abs(cand-num)==abs(closest-num) && cand<closest)){
                closest = cand;
            }
        }

        return to_string(closest); 
    }
};