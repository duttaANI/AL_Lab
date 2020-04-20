/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {} // A constructor https://leetcode.com/problems/add-two-numbers/discuss/122357/c-what-does-listnodeint-x-valx-nextnull-mean
 * };
 */
class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ListNode ans;
        int x,y,z,carry=0;
        
        ListNode* cur = NULL;  // for starting
        ListNode* ans = NULL;
        x = l1->val;
        y = l2->val;
        z = x + y + carry;
        carry = z/10;
        z = z%10;
        l1 = l1->next;
        l2 = l2->next;
        cur = new ListNode(z);
        ans = cur;
        
        while(l1 != NULL && l2 !=NULL)
        {
            x = l1->val;
            y = l2->val;
            z = x + y + carry;
            carry = z/10;
            z = z%10;
            l1 = l1->next;
            l2 = l2->next;
            cur->next = new ListNode(z);
            cur = cur->next;
        }
        ListNode* cur2 = NULL;
        if( l1 != NULL)
            cur2 = l1;
        else if(l2 != NULL)
            cur2 = l2;
        
        while(cur2 != NULL)
        {
            z = cur2->val + carry;
            carry = z/10;
            z = z%10;
            cur2 = cur2->next;
            cur->next = new ListNode(z);
            cur = cur->next;
           
        }
        
        // for last carry
        if(carry>0)
            cur->next = new ListNode(carry);
        
        return ans;
        
    }
};