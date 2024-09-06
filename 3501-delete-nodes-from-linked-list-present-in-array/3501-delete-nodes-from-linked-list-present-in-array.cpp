class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> u(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* temp = head;
        ListNode* prev = dummy;
        while (temp != NULL) {
            if (u.find(temp->val) != u.end()) {
                //we have to delete
                prev->next = temp->next;
            }
            else prev = temp;
            temp = temp->next;
        }
        return dummy->next;
    }
};
