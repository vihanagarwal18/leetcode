class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
       queue<pair<TreeNode*,TreeNode*>> q; //child parent
       q.push({root,NULL});
       while(!q.empty()){
        int n=q.size();
        map<TreeNode*,int> mp; //parent aur uske bacho ka sum
        int totalsum=0;
        vector<pair<TreeNode*,TreeNode*>> cousins;
        for(int i=0;i<n;i++){
            auto cur=q.front(); 
            q.pop();
            totalsum+=cur.first->val;
            mp[cur.second]+=cur.first->val;
            cousins.push_back(cur);
            if(cur.first->left) q.push({cur.first->left,cur.first});
            if(cur.first->right) q.push({cur.first->right,cur.first});
        }
        for(auto it:cousins) it.first->val=totalsum-mp[it.second];
       }
       return root; 
    }
};