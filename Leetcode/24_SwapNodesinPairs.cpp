/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        // get length 
        ListNode* cur = head; int len=0;
        while(cur) {
            cur=cur->next; ++len;
        }
        
        ListNode* cur1 = head;   ListNode* cur2 = head->next;  ListNode* head2 = cur2;
        ListNode* cur3=NULL;
        
        while (cur2->next!=NULL) {
            
            cur1->next = cur2->next;
            cur2->next = cur1;
            
            cur3 = cur1;
            
            if(cur1->next->next!=NULL) { // so that cur2 is not NULL
                cur1 = cur1->next;
                cur2 = cur1->next;
          
                cur3->next = cur2;
            }
            else
                break;
        }
        
        if(len%2==0) {
            cur2->next = cur1;
            cur1->next = NULL;
        }
        
        return head2;
    }
};
