/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int maximum){
        if(root==NULL) return 0;
        int result=0;
        if(root->val>=maximum){
            result++;
            maximum=max(maximum,root->val);
        }
        if(root->left!=NULL){
            result+=solve(root->left,maximum);
        }
        if(root->right!=NULL){
            result+=solve(root->right,maximum);
        }
        return result;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int result=1;
        result+=solve(root->left,root->val);
        result+=solve(root->right,root->val);
        return result;
    }
};