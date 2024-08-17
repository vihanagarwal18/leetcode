class Solution {
public:
    void solve(TreeNode* root, int target, vector<int>& temp, vector<vector<int>>& result) {
        if (root == NULL) return;
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL && target == root->val) {
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        if (root->left != NULL) {
            solve(root->left, target - root->val, temp, result);
        }
        if (root->right != NULL) {
            solve(root->right, target - root->val, temp, result);
        }
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(root, targetSum, temp, result);
        return result;
    }
};
