ListNode* Solution::detectCycle(ListNode* A) {
    set<ListNode*> s;

    while(A){
        if(s.find(A)!=s.end()){
            return A;
        }
        s.insert(A);
        A = A->next;
    }
    
    return NULL;
}