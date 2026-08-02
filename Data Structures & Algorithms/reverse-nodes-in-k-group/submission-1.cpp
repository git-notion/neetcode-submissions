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
//Improviing variable names and preventing memory leak
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* prevTail=nullptr;
        int c=0;
        while(curr!=0){
            c++;
            curr=curr->next;
        }
        curr=head;
        ListNode* prev=nullptr;
        for(int i=0;i<c/k;i++){
            ListNode* now=curr;
            for(int j=0;j<k;j++){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            
            now->next=curr;
            if(prevTail){
                prevTail->next=prev;
            }else{
                head=prev;
            }
            prevTail=now;
            prev=now;
        }
        return head;
    }
};
