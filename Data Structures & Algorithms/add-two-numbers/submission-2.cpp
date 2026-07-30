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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr=l1,*cirr=l2,*prev=NULL;
        int carry=0;
        while(curr!=NULL&&cirr!=NULL){
            curr->val+=cirr->val+carry;
            if(curr->val>9){
                carry=curr->val/10;
                curr->val=curr->val%10;
            }else carry=0;
            prev=curr;
            curr=curr->next;
            cirr=cirr->next;
        }
        while(curr!=NULL){
            curr->val+=carry;
            if(curr->val>9){
                carry=curr->val/10;
                curr->val=curr->val%10;
            }else carry=0;
            prev=curr;
            curr=curr->next;
        }
        while(cirr!=NULL){
            prev->next=new ListNode(cirr->val+carry);
            prev=prev->next;
            if(prev->val>9){
                carry=prev->val/10;
                prev->val=prev->val%10;
            }else carry=0;
            cirr=cirr->next;
        }
        if(carry!=0){
            prev->next=new ListNode(carry);
        }
        return l1;
    }
};
