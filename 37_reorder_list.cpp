class Solution {
public:
    void reorderList(ListNode* head) {
		ListNode *ret = new ListNode();
		ListNode *temp;
		vector<ListNode *> lst;

		while (head) {
			lst.push_back(head);
		}

		int len = lst.size();
		int l = 0;
		int r = len - 1;

        temp = ret;
		while (l < r) {
            cout << lst[l];
			ret->next = lst[l++];
			ret = ret->next;
			if (l < r) break ;
            cout << lst[r];
			ret->next = lst[r--];
			ret = ret->next;
		}
        head = temp->next;
    }
};
