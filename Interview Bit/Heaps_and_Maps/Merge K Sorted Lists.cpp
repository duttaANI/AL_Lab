ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int n = A.size();
    if(n==0) return NULL;
    priority_queue< int, vector<int> , greater<int> >pq;
    for( ListNode * i : A ){
        if(i==NULL) continue;
        ListNode * temp = i;
        while( temp ){
            pq.push(temp->val);
            temp = temp ->next;
        }
    }
    
    if(pq.size()==0) return NULL;


    int f = pq.top(); pq.pop();
    ListNode * head = new ListNode (f);
    ListNode * cur = head;
    while( pq.size() ){
        f = pq.top();
        cur -> next = new ListNode  (f); pq.pop();
        cur = cur->next;
    }

    return head;
}