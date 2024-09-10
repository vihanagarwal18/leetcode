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
    int gcd(int a, int b){
        int result = min(a, b);
        while (result>0) {
            if (a%result==0 && b%result==0) {
                break;
            }
            result--;
        }
        return result;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* firstnode=head;
        ListNode* secondnode=head->next;
        while(secondnode!=NULL && firstnode!=NULL){
            ListNode* nextnode=secondnode->next;
            int g=gcd(secondnode->val,firstnode->val);
            ListNode* temp=new ListNode(g);
            firstnode->next=temp;
            temp->next=secondnode;
            firstnode=secondnode;
            secondnode=nextnode;
        }
        return head;
    }
};