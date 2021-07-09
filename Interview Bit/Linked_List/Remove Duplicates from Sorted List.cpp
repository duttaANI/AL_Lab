ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode * ans = A;
    ListNode * cur = A;
    while( cur ){
        ListNode * temp = cur;
        while( temp && ( temp->val == cur->val )  ){
            temp = temp->next;
        }
        cur->next = temp;
        cur = cur->next;
    }
    return ans;
}