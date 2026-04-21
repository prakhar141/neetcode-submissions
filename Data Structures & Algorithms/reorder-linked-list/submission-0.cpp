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
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=slow->next;
        slow->next=nullptr;
        while(curr){
            ListNode* nextTemp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextTemp;
        }
        ListNode* l1=head;
        ListNode* l2=prev;
        while(l2){
            ListNode* t1=l1->next;
            ListNode* t2=l2->next;
            l1->next=l2;
            l2->next=t1;
            l1=t1;
            l2=t2;
        }
        
    }
};
