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
    int minimumOperations(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return 0;
        int result=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<pair<int,int>> temp;
            for(int i=0;i<n;i++){
                auto p=q.front();
                q.pop();
                temp.push_back({p->val,i});
                if(p->left!=NULL) q.push(p->left);
                if(p->right!=NULL) q.push(p->right);
            }

            // now i have this vector now i want to calculate number of swaps
            sort(temp.begin(),temp.end());
            int i=0;
            while(i<n){
                if(temp[i].second!=i){
                    swap(temp[i],temp[temp[i].second]);
                    result++;
                }
                else i++;
            }
        }
        return result;
    }
};