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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *ret = head;
        ListNode *prev = NULL;
        ListNode *temp = head;
		
        int len = 0;
        while (temp) {
            temp = temp->next;
            len++;
        }
		int i = 0;
		while (head && i < len - n) {
            prev = head;
			head = head->next;
			i++;
		}
        if (prev) {
            if (head)
                prev->next = head->next;
        } else {
            ret = ret->next;
        }
        
        return ret;
    }
};
