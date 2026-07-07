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
        ListNode* curr = head;
        int size = 0;
        while(curr){
            size++;
            curr = curr->next;
        }
        size++;
        curr = head;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next=head;
        int a=0;
        while(curr){
            a++;
            if(size-a==n){
                prev->next=curr->next;
                delete curr;
                break;
            }
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;

    }
};
