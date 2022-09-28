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
    ListNode *detectCycle(ListNode *head) {
        ListNode *l = head;
        ListNode *r = head;
        while (r && r->next) {
            l = l->next;
            r = r->next->next;
            if (l == r) break ;
        }
        if (!r || !r->next) return nullptr;
        
        r = head;
        while (r != l) {
            r = r->next;
            l = l->next;
        }
        return r;
    }
};
