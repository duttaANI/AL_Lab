// link : https://leetcode.com/problems/merge-k-sorted-lists/discuss/10531/Sharing-my-straightforward-C%2B%2B-solution-without-data-structure-other-than-vector

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
    
   ListNode* mergeKLists( vector<ListNode*> &lists ){
       if( lists.empty() ){
           return nullptr;
       }
       while( lists.size()>1 ){
           lists.push_back( mergeTwoLists(lists[0],lists[1]) );
           lists.erase(lists.begin());
           lists.erase(lists.begin());
       }
       return lists.front();
   }
private: 
    ListNode* mergeTwoLists( ListNode* l1, ListNode* l2 ){
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        if( l1->val <= l2->val ){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};


// My TLE code

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans_head = NULL;
        ListNode* temp = NULL;
            

        if     ( (l1 && !l2) || (l1 && l2 && (l1->val<l2->val) ) )
        {
            ans_head = new ListNode(l1->val);
            l1=l1->next;
            temp = ans_head;
        }
        else if( (l2 && !l1) || (l2 && l1 && (l2->val<=l1->val) ) )
        {
            ans_head = new ListNode(l2->val);
            l2=l2->next;
            temp = ans_head;
        }

        

        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                l1=l1->next;
            }
            else
            {
                temp->next = new ListNode(l2->val);
                temp = temp->next;
                l2=l2->next;
            }
        }

        while(l1)
        {
            temp->next = new ListNode(l1->val);
            temp = temp->next;
            l1=l1->next;
        }

        while(l2)
        {
            temp->next = new ListNode(l2->val);
            temp = temp->next;
            l2=l2->next;
        }

        return ans_head;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        if(lists.size()==0)
            return ans;
        
        if(lists.size()==1){
            ans = lists[0];
            return ans;
        }
            
        
        ans =  mergeTwoLists(lists[0], lists[1]);
        int i =2;
        
        while( i<lists.size())
        {
            ans = mergeTwoLists(ans, lists[i]);
            ++i;
        }
        
        
        return ans;
    }
};






































































