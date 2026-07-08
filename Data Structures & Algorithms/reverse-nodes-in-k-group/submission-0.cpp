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

    void reverse(ListNode* head,int k){
        ListNode* curr=head->next;
        int n=k;
        while(n-1){
            n--;
            curr=curr->next;
        }
        ListNode* prev = curr->next;
        ListNode* next = NULL;
        
        curr=head->next;
        for(int i=0;i<k;i++){
            next = curr->next;
            curr->next = prev;
            prev= curr;
            curr=next;
        }
        head->next = prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            n++;
        }
        if(n<k){
            return head;
        }
        curr=dummy;
        int total = n/k;
        for(int i=0;i<total;i++){
            reverse(curr,k);
            int j=0;
            while(j<k){
                curr=curr->next;
                j++;
            }
        }
        return dummy->next;
    }
};
