/*
The issue with the increased time complexity might be due to the way memoization is managed and
passed around. When the memoization arrays are defined inside the function and passed as parameters,
it introduces additional overhead compared to having them as global variables.
To address this while maintaining the encapsulation, you can define the memoization arrays within the 
Solution class but outside the numTeams function. This approach ensures that the arrays are only 
initialized once and reused for each test case, thus reducing the initialization overhead.
*/
class Solution {
public:
    int dp1[1002][1002][4];
    int dp2[1002][1002][4];

    int findans2(vector<int>& rating, int i, int prev, int cnt) {
        if (cnt == 3) {
            return 1;
        }

        if (i < 0) {
            if (cnt == 3) {
                return 1;
            }
            return 0;
        }

        if (prev != -1 && dp2[i][prev][cnt] != -1) {
            return dp2[i][prev][cnt];
        }

        int take = 0;
        if ((prev == -1) || (rating[i] > rating[prev])) {
            take = findans2(rating, i - 1, i, cnt + 1);
        }

        int nontake = findans2(rating, i - 1, prev, cnt);
        if (prev != -1) {
            dp2[i][prev][cnt] = take + nontake;
        }
        return take + nontake;
    }

    int findans1(vector<int>& rating, int i, int prev, int cnt) {
        if (cnt == 3 ) {
            return 1;
        }

        if (i < 0) {
            return 0;
        }

        if (prev != -1 && dp1[i][prev][cnt] != -1) {
            return dp1[i][prev][cnt];
        }

        int take = 0;
        if ((prev == -1) || (rating[i] < rating[prev])) {
            take = findans1(rating, i - 1, i, cnt + 1);
        }

        int nontake = findans1(rating, i - 1, prev, cnt);
        if (prev != -1) {
            dp1[i][prev][cnt] = take + nontake;
        }
        return take + nontake;
    }

    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int prev = -1;
        int cnt = 0;

        // Initialize memoization arrays using memset
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        return findans1(rating, n - 1, prev, cnt) + findans2(rating, n - 1, prev, cnt);
    }
};