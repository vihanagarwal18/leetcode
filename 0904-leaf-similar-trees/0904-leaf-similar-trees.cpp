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
    void sequence(TreeNode* root,vector<int>& result){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) result.push_back(root->val);
        if(root->left!=NULL) sequence(root->left,result);
        if(root->right!=NULL) sequence(root->right,result); 
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        sequence(root1,seq1);
        vector<int> seq2;
        sequence(root2,seq2);
        if(seq1==seq2) return true;
        return false;
    }
};