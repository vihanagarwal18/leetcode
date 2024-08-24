class Solution {
public:
    int solve(TreeNode* root,int &maxLength,bool right)
    {
        if(root==NULL) return 0;
        int ans_left=0;
        int ans_right=0;
        if(root->left) {
            int temp=1+solve(root->left,maxLength,1);
            ans_left = max(ans_left,temp);
        }
        if(root->right) {
            int temp=1+solve(root->right,maxLength,0);
            ans_right = max(ans_right,temp);
        }
        maxLength = max(maxLength,max(ans_left,ans_right));
        if(right) return ans_right;
        return ans_left;
    }
    int longestZigZag(TreeNode* root) 
    {
        int maxLength=0;
        int temp=solve(root,maxLength,1);
        return maxLength;
    }
};