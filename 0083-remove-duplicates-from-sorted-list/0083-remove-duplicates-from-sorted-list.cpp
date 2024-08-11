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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        unordered_set<int> u;
        u.insert(head->val);
        ListNode* temp=head->next;
        ListNode* prev=head;
        while(temp!=NULL){
            if(u.find(temp->val)!=u.end()){
                //this is duplicate
                prev->next=temp->next;
                if(temp->next!=NULL) temp=temp->next;
                else temp=temp->next;
            }
            else{
                u.insert(temp->val);
                prev=temp;
                temp=temp->next;
            }
        }
        return head;

    }
};