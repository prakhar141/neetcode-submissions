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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head|| !head->next) return head;
        ListNode* curr=head;
        while(curr->next){
            int g=std:: gcd(curr->val,curr->next->val);
            ListNode* gcdNode=new ListNode(g,curr->next);
            curr->next=gcdNode;
            curr=gcdNode->next;
        }
        return head;
        
    }
};