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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) return NULL;
        
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        int count=0;
        
        while(l1!=l2 && count<3) // counnt < 3 for non intersecting cases
        {
            if(l1->next!=NULL)
                l1=l1->next;
            else
            {
                l1 = headB;++count;
            }
                
            
            if(l2->next!=NULL)
                l2=l2->next;
            else
            {
                l2 = headA;++count;
            }
                
        }
        
        if(l1==l2)
            return l1;
        else
            return NULL;
    }
};