/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* duplicatehead=new Node(0); //dummy
        Node* temp=head;
        Node* ptr=duplicatehead;
        map<Node*,Node*> m; //node newnode
        while(temp!=NULL){
            Node* t=new Node(temp->val);
            ptr->next=t;
            m[temp]=t;
            ptr=ptr->next;
            temp=temp->next;
        }
        //now connect random pointer
        temp=head;
        ptr=duplicatehead->next;
        while(temp!=NULL){
            ptr->random=m[temp->random];
            ptr=ptr->next;
            temp=temp->next;
        }
        return duplicatehead->next; 
    }
};