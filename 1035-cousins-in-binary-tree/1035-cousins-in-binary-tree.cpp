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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y) return false;
        bool foundx=false;
        bool foundy=false;
        queue<pair<TreeNode*,TreeNode*>> q;
        if(root->left) q.push({root->left,root});
        if(root->right) q.push({root->right,root});
        while(!q.empty()){
            int n=q.size();
            TreeNode* parentx;
            TreeNode* parenty;
            for(int i=0;i<n;i++){
                auto t=q.front();
                if(t.first->left) q.push({t.first->left,t.first});
                if(t.first->right) q.push({t.first->right,t.first});
                q.pop();
                if(t.first->val==x){
                    foundx=true;
                    parentx=t.second;
                }
                else if(t.first->val==y){
                    foundy=true;
                    parenty=t.second;
                }
            }
            if(foundx || foundy){
                if(foundx && foundy && parentx!=parenty) return true;
                return false;
            }
        }
        cout<<"hello"<<endl;
        return false ;//one of x or y not found // dummy case code will not reach here
    }
};