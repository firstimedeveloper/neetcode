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
    ListNode* plusOne(ListNode* head) {
        ListNode *notNine = head;
        ListNode *ret;
        
        ret = new ListNode;
        ret->next = head;
        head = ret;
        for (; head != nullptr; head = head->next) {
            if (head->val != 9)
                notNine = head;
        }
        notNine->val++;
        notNine = notNine->next;
        for (; notNine != nullptr; notNine = notNine->next) {
            notNine->val = 0;
        }
        if (ret->next->val == 0) {
            ret->val = 1;
            return ret;
        }
        return ret->next;
    }
};
