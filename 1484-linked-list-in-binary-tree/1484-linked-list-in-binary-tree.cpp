/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head,ListNode* current,TreeNode* root){
        if(current==NULL) return true;
        if(root==NULL) return false;
        if(current->val==root->val){
            current=current->next;
        }
        else if(head->val==root->val){
            head=head->next;
        }
        else current=head;
        return solve(head,current,root->left) || solve(head,current,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(head,head,root);
        // if (head == NULL) return true;
        // if (root == NULL) return false;
        // if (root->val == head->val) {

        //     if (isSubPath(head->next, root->left) || isSubPath(head->next, root->right)) return true;
        // }
        // return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
