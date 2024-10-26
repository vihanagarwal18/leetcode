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
    int findheights(TreeNode* &root,unordered_map<int,int>& height){
        if(root==NULL)  return -1;   
        height[root->val]=1+max(findheights(root->left,height),findheights(root->right,height));
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int,int> height;
        int h=findheights(root,height);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int maxi=INT_MIN;
            int secMaxi=INT_MIN;
            for(int i=0;i<n;i++){ //sare nodes ek level ki
                auto node=q.front();
                q.pop();
                if(height[node->val]>maxi){
                    secMaxi=maxi;
                    maxi=height[node->val];
                }
                else if(height[node->val]>=secMaxi){
                    secMaxi=height[node->val];
                }
                q.push(node);
            }
            //har level ki max height and second max height nikal li

            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                if(height[node->val]==maxi){
                    //vo node max hogi tabhi toh uske hatne main change ayega 
                    if(secMaxi==maxi) height[node->val]=h; //even if highest height tree is removed we will get height h
                    else if(secMaxi!=INT_MIN) height[node->val]=h-maxi+secMaxi; //if tallest node is removed then what will be the height
                    else if(secMaxi==INT_MIN) height[node->val]=h-maxi-1; //there is only max height but no second max then what will be height
                }
                else{
                    //ese node ko hatane se khuch nhi hoga
                    height[node->val]=h;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        vector<int> ans;
        for(auto& query:queries){
            ans.push_back(height[query]);
        }
        return ans;
    }
};