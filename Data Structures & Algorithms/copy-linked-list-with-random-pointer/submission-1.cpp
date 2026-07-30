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
        if(head==NULL){
            return head;
        }
        unordered_set<Node*>a;
        unordered_map<Node*,Node*>b;
        Node* curr=head;
        Node* rtn =new Node(head->val);
        Node* ans=rtn;
        while(curr!=NULL){
            ans->val=curr->val;
            a.insert(curr);
            b[curr]=ans;
            if(curr->next!=NULL)
                ans->next=new Node(0);
            ans=ans->next;
            curr=curr->next;
        }
        curr=head;
        ans=rtn;
        while(curr!=NULL)
        {
            Node* temp=curr->random;
            ans->random=b[temp];
            ans=ans->next;
            curr=curr->next;
        }
        return rtn;
    }
};
