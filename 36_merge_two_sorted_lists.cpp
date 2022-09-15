class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ret;
        ListNode *cur;
        
		// this creates a dummy node to make the logic below easier
		// don't need to take care of edge case of ret being null.
        ret = new ListNode;
        cur = ret;
        while (cur) {
            if (list1 && list2) {
                if (list1->val > list2->val) {
                    cur->next = list2;
                    list2 = list2->next;
                } else {
                    cur->next = list1;
                    list1 = list1->next;
                }
                cur = cur->next;
            } else if (list1 && !list2) {
                cur->next = list1;
                break ;
            } else if (!list1 && list2) {
                cur->next = list2;
                break ;
            } else break ;        
        }
		// since ret is a dummy node, the actual head starts at next.
        return ret->next;
    }
};
