class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int total = rows * cols;
        int r = rStart, c = cStart;
        int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up
        int steps = 1; 
        int count = 0; 
        res.push_back({r, c}); 
        count++;
        while (count < total) {
            for (int i = 0; i < steps; ++i) {
                if (direction == 0) c++;        // Move right
                else if (direction == 1) r++;   // Move down
                else if (direction == 2) c--;   // Move left
                else if (direction == 3) r--;   // Move up
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    res.push_back({r, c});
                    count++;
                }
            }
            direction = (direction + 1) % 4; //change direction
            // Increase steps after completing both horizontal and vertical moves
            if (direction == 0 || direction == 2) steps++;
        }
        return res;
    }
};
