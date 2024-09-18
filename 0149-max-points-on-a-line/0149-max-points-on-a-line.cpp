class Solution {
public:
    int gcd(int a, int b) {
        if(b==0) return a;
        return  gcd(b, a % b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return n;
        int result = 0;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> slopeCount;
            int duplicates = 1;  //current point as duplicate
            int localMax = 0;
            for (int j = 0; j < n; j++) {
                if (i==j) continue;  //skip for same points
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }
                int g = gcd(dx, dy);
                dx=dx/g;//normalizing the slope
                dy=dy/g;//normalizing the slope
                if (dx < 0) {
                    //for negative slopes (make dx positive) so dy  will be made negative
                    dx = -dx;
                    dy = -dy;
                } 
                else if (dx == 0) {
                    // slope is vertical
                    dy=1;
                }
                
                slopeCount[{dx, dy}]++;
                localMax = max(localMax, slopeCount[{dx, dy}]);
            }
            result = max(result, localMax + duplicates);
        }
        return result;
    }
};