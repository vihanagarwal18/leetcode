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
    void flatten(TreeNode* root) {
        // root left right should be the order
        if(root==NULL || (root->left==NULL && root->right==NULL)) return ;
        if(root->left) flatten(root->left);        
        if(root->right) flatten(root->right);
        TreeNode* temp=root->left;
        if(temp){
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
    }
};