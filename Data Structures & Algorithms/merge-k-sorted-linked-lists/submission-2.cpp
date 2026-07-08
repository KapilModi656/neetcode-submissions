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
    ListNode* merge(ListNode* p,ListNode* q){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr=dummy;
        while(p&&q){
            if(p->val>q->val){
                curr->next = q;
                q=q->next;
            }
            else{
                curr->next = p;
                p=p->next;
            }
            curr=curr->next;
        }
        while(p){
            curr->next=p;
            p=p->next;
            curr=curr->next;
        }
        while(q){
            curr->next=q;
            q=q->next;
            curr=curr->next;
        }
        return dummy->next;
    }
    ListNode* mergeLists(vector<ListNode*>& lists,int start,int end){
        if(end-start+1>2){
            int mid = (start+end)/2;
            ListNode* first = mergeLists(lists,start,mid);
            ListNode* second = mergeLists(lists,mid+1,end);
            return merge(first,second);
        }
        else{
            if(end-start+1==2){
                return merge(lists[start],lists[end]);
            }
            else if(end==start){
                return lists[end];
            }
            else{
                return NULL;
            }
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* curr = lists[0];
        int n=lists.size();
        
        return mergeLists(lists,0,n-1);
    }
};
