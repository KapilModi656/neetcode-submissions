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
        map<Node*,Node*> mp;
        Node* curr = head;
        Node* dummy = new Node(0);
        Node* prev = dummy;
        
        while(curr){
            Node* node = new Node(curr->val);
            prev->next = node;
            prev=node;
            mp[curr] = node;
            curr=curr->next;
        }
        curr=head;
        while(curr){
            Node* deep = mp[curr];
            deep->random = mp[curr->random];
            curr=curr->next;
        }
        return dummy->next;
    }
};
