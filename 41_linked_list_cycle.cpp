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
    bool hasCycle(ListNode *head) {
        ListNode *l = head;
        ListNode *r = head;

		while (l && r && r->next) {
			l = l->next;
			r = r->next->next;
			if (l == r)
				return true;
		}
		return false;
    }
};
