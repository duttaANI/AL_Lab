class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode *slow(head), *fast(head);
        
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Make fast the head of right half.
        // Note that the right half may have one less node than left half
        fast = slow->next;
        
        slow->next = nullptr; // set tail of left half to be null
        
        
        // Right now slow is the head of left half,
        // fast is the head of right half
        
        bool reval(true);
        
        for (ListNode *left = head, *right = reverseList(fast); left && right; left = left->next, right = right->next) {
            if (left->val != right->val) {
                reval = false;
                reverseList(right); //reverse back
                break;
            }
        }
        
        slow->next = fast;
        
        return reval;
    }
private:
    ListNode* reverseList(ListNode *head) {
        ListNode dummy(0), *next(nullptr);
        
        while (head) {
            next = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = next;
        }
        
        return dummy.next;
    }
};