class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        multiset<int> u(tokens.begin(), tokens.end());
        //multi set allow us to have duplicate values 

        //set and multi set store data in increasing order(smallest first)
        int result = 0;
        int temp = 0;
        while (!u.empty()) {
            auto smaller = u.begin();      
            // auto larger = u.rbegin();  
            auto larger = prev(u.end()); // to access last element 
            //erase function dont take reverse iterator as a argument
            if (*smaller <= power) {
                power -= *smaller;
                temp++;
                u.erase(smaller); 
            } else {
                if (temp > 0) {
                    power += *larger;
                    temp--;
                    u.erase(larger); 
                } else {
                    break;
                }
            }
            result =max(temp, result);
        }
        return result;
    }
};
