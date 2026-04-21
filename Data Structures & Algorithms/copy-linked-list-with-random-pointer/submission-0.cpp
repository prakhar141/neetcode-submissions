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
        if (!head){
            return nullptr;
        }
        unordered_map <Node*,Node*> clones;
        Node* curr=head;
        while(curr){
            clones[curr]=new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr){
            clones[curr]->next=clones[curr->next];
            clones[curr]->random=clones[curr->random];
            curr=curr->next;
        }
        return clones[head];
    }   
    
};
