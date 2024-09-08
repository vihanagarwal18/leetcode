class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, NULL);
        int n = 0;
        ListNode* temp=head;
        while (temp != NULL) {
            temp=temp->next;
            n++;
        }
        int each = n / k;
        int extra = n % k;
        ListNode* temp2 = head;
        for (int i = 0; i<k && temp2 != NULL; i++) {
            result[i]=temp2;
            ListNode*temp3=temp2;
            int partSize=each;
            if(extra>0){
                partSize++;
                extra--;
            }
            for (int j = 1; j < partSize; j++) {
                temp3 = temp3->next;
            }
            temp2 = temp3->next;
            temp3->next = NULL;
        }
        
        return result;
    }
};
