#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	// ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
		ListNode *ret = new ListNode();
		ListNode *temp;
		vector<ListNode *> lst;

		while (head) {
			lst.push_back(head);
            head = head->next;
		}

		int len = lst.size();
		int l = 0;
		int r = len - 1;

        temp = ret;
		while (l <= r) {
			printf("%d %d\n", l, lst[l]->val);
			ret->next = lst[l++];
			ret = ret->next;
			if (l > r) break ;
            printf("%d %d\n", r, lst[r]->val);
			ret->next = lst[r--];
			ret = ret->next;
		}
		ret->next = NULL;
        head = temp->next;
    }
};

int main() {
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;

	Solution sol;

	sol.reorderList(l1);
	while (l1) {
		printf("%d ", l1->val);
		l1 = l1->next;
	}

}
