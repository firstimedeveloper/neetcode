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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur, *ret = new ListNode(0);
        int carry = 0;
        
        cur = ret;
        while (l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int val = a + b + carry;
            carry = val ? val / 10 : 0;
            ListNode *temp = new ListNode(val % 10);
            cur->next = temp;
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry)
            cur->next = new ListNode(carry, NULL);
        return ret->next;
    }
};
