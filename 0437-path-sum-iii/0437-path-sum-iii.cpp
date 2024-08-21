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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        int proot = countpath(root, targetSum);
        int pl = pathSum(root->left, targetSum);
        int pr = pathSum(root->right, targetSum);
        return proot+pl+pr;
    }
    int countpath(TreeNode* node, long long targetSum) {
        if (node == NULL) return 0;
        int count = 0;
        if (node->val == targetSum) count++;
        count += countpath(node->left,targetSum-node->val);
        count += countpath(node->right,targetSum-node->val);
        return count;
    }
};

// class Solution {
// public:
//     int pathSum(TreeNode* root, int targetSum) {
        
//         if(root==NULL) return 0;
//         if(root->right==NULL && root->left==NULL)return root->val==targetSum;
//         int result=0;
//         if(root->left!=NULL){
//             result+=pathSum(root->left,targetSum-root->val); //take root
//             result+=pathSum(root->left,targetSum); //not take root
//         }
//         if(root->right!=NULL){
//             result+=pathSum(root->right,targetSum-root->val); //take root
//             result+=pathSum(root->right,targetSum); //not take root
//         }
//         return result;
//     }
// };