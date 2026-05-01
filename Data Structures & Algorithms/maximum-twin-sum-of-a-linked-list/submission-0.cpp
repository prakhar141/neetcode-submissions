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
    int pairSum(ListNode* head) {
       ListNode* fast=head;
       ListNode*  slow=head;
       while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode* prev=nullptr;
       ListNode* curr=slow;
       while(curr!=nullptr){
        ListNode* nextTemp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextTemp;
       }
       int maxSum=0;
       ListNode* firstHalf=head;
       ListNode* secondHalf=prev;
       while(secondHalf!=nullptr){
        int sum=firstHalf->val+secondHalf->val;
        maxSum=max(sum,maxSum);
        firstHalf=firstHalf->next;
        secondHalf=secondHalf->next;
       }
       return maxSum;

    }
};