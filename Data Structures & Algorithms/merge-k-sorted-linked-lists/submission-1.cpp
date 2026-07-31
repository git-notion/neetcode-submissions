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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int>u;
        for(auto i:lists){
            ListNode* curr=i;
            while(curr!=NULL){
                u[curr->val]++;
                curr=curr->next;
            }
        }
        ListNode* head=new ListNode(0);
        ListNode* curr=head;
        for(auto i:u){
            for(int j=0;j<i.second;j++){
                curr->next=new ListNode(i.first);
                curr=curr->next;
            }
        }

        return head->next;
    }
};
