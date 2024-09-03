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
    ListNode* findkthnode(ListNode* temp,int k){
        k=k-1;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* nextnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextnode;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        //ListNode* kthnode=NULL;
        ListNode* nextnode=NULL;
        ListNode* prevnode=NULL;
        while(temp!=NULL){
            ListNode* kthnode=findkthnode(temp,k);
            if(kthnode==NULL){
                //we dont need to reverse
                if(prevnode!=NULL)  prevnode->next=temp;
                //if prevnode is null then we never revered at all
                break;
            }
            //reverse from temp to kthnode
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            //now we can reverse it easily
            reverse(temp);
            if(temp==head){
                //its first grp
                head=kthnode;
            }
            else{
                //its not first grp
                prevnode->next=kthnode;
            }
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};