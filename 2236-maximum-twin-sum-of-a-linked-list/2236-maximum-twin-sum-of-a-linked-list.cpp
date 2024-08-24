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
    int pairSum(ListNode* head) {
        //all node values are positive
        int maxsum=0;
        ListNode* temp=head;
        ListNode* temp2=head;
        while(temp2!=NULL && temp2->next!=NULL){
            temp=temp->next;
            temp2=temp2->next->next;
        }
        //this temp is our middle node if we reverse temp we can easily solve the ques

        ListNode* t=temp;
        ListNode* prev=NULL;
        while(t!=NULL){
            ListNode* front=t->next;
            t->next=prev;
            prev=t;
            t=front;
        }

        //this prev is our reverse
        ListNode* p=prev;
        ListNode* q=head;
        while(p!=NULL && q!=NULL){
            int sum=p->val+q->val;
            maxsum=max(sum,maxsum);
            p=p->next;
            q=q->next;
        }
        return maxsum;
    }
};

