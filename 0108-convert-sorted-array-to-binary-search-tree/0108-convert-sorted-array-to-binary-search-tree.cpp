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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return NULL;
        TreeNode* root=new TreeNode(nums[n/2]);
        vector<int> lefthalf;
        vector<int>righthalf;
        for(int i=0;i<n/2;i++){
            lefthalf.push_back(nums[i]);
        }
        for(int i=(n/2)+1;i<n;i++){
            righthalf.push_back(nums[i]);
        }
        root->left=sortedArrayToBST(lefthalf);
        root->right=sortedArrayToBST(righthalf);
        return root;
    }
};