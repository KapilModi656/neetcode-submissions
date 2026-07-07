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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int residual = 0;
        while(l1||l2){
            if(l1&&l2){
                int sumi = l1->val+l2->val+residual;
                residual = sumi/10;
                ListNode* node = new ListNode(sumi%10);
                curr->next = node;
                l1 = l1->next;
                l2 = l2->next;
                
            }
            else if(l1){
                int sumi = l1->val+residual;
                residual = sumi/10;
                ListNode* node = new ListNode(sumi%10);
                curr->next = node;
                l1 = l1->next;
            }
            else{
                int sumi = l2->val+residual;
                residual = sumi/10;
                ListNode* node = new ListNode(sumi%10);
                curr->next = node;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(residual){
            ListNode* node = new ListNode(residual);
            curr->next = node;
        }
        return dummy->next;
    }
};
