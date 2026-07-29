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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur=head;
        ListNode* prev=NULL;
        int s=0;
        while(cur!=NULL){
            s++;
            cur=cur->next;
        }
        cur=head;
        int target=s-n,c=0;
        if(target==0){
            return head->next;
        }
        while(cur!=NULL&&c<target){
            prev=cur;
            cur=cur->next;
            c++;
        }
        prev->next=cur->next;
        cout<<s;
        return head;
    }
};
