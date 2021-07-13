ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode * cur  = A;
    int length = 0;
    while(cur){
        ++length;
        cur = cur ->next;
    }
    
    if( B >= length ){
        return A->next;
    }
    cur = A;
    int temp = length -B-1;
    while(temp  ){
        cur = cur->next;
        --temp;
    }
    
    // cout << cur->val << " val \n";
    cur->next = cur->next->next;
    
    return A;
}