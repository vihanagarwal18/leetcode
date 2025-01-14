class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_set<int> u;
        vector<int> result;
        for(int i=0;i<n;i++){
            u.insert(A[i]);
            u.insert(B[i]);
            int count=2*(i+1)-u.size();
            result.push_back(count);
        }
        return result;
    }
};