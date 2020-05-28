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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;  ListNode* temp = head;
        while(cur) {
            while(cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            temp->next = cur->next;
            temp = cur->next;
            cur = cur->next;
        }
        return head;
    }
};