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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next;
        ListNode* curr = head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        int size = 0;
        while(curr){
            size++;
            curr = curr->next;
        }
        int a=0;
        ListNode* middle = NULL;
        curr=head;
        while(curr){
            a++;
            if(a == ((size+1)/2)){
                middle = curr;
                break;
            }
            curr = curr->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        curr = head;
        ListNode* next = NULL;
        ListNode* second = reverse(middle);
        ListNode* snext = NULL;
        while(curr&&second){
            next = curr->next;
            curr->next = second;
            snext = second->next;
            second->next =next;
            second = snext;
            curr =next;
        }
      

    }
};
