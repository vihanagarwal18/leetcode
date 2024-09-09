/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        ListNode* temp = head;
        int i = 0, j = 0;
        int index = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (temp != nullptr) {
            result[i][j] = temp->val;
            temp = temp->next;
            int x = i + directions[index][0];
            int y = j + directions[index][1];
            if (x < 0 || y < 0 || x >= m || y >= n || result[x][y] != -1) {
                index = (index + 1) % 4;
                x = i + directions[index][0];
                y = j + directions[index][1];
            }    
            i = x;
            j = y;
        }
        return result;
    }
};
