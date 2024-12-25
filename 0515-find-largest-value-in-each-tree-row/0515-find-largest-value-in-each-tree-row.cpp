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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int maxx=INT_MIN;
            for(int i=0;i<n;i++){
                auto p=q.front();
                q.pop();
                maxx=max(p->val,maxx);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            result.push_back(maxx);
        }
        return result;
    }
};