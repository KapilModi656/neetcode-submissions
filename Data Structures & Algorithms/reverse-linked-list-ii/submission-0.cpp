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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr=head;
        int i=0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* start = dummy;
        ListNode* end = dummy;
        while(curr){
            i++;
            if(i==left-1){
                start = curr;
            }
            if(i==right){
                end = curr;
                break;
            }
            curr=curr->next;
        }
        ListNode* next = start->next;
        start->next = end;
        ListNode* prev=end->next;
        curr=next;
        i=0;
        while(i!=right-left+1){
            next = curr->next;
            curr->next=prev;
            prev = curr;
            curr=next;
            i++;
        }
        return dummy->next;

    }
};