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
	void reverseList(ListNode **head) {
		ListNode *prev = NULL;
		ListNode *temp;

		while (*head) {
			temp = (*head)->next;
			(*head)->next = prev;
			prev = *head;
			*head = temp;
		}
		*head = prev;
	}

    void reorderList(ListNode *head) {
		ListNode *tail = head;
		ListNode *temp = head;
		int n = 0;
		while (temp) {
			printf("%d ", temp->val);
			temp = temp->next;
			n++;
		}
		printf("\n");
		int i = 0;
		while (tail->next && i < n / 2) {
			printf("%d ", tail->val);
			tail = tail->next;
			i++;
		}
		temp = tail->next;
		tail->next = NULL;
		tail = temp;
		printf("\n");
		reverseList(&tail);

		ListNode *cur = tail;
		while (cur) {
			printf("%d ", cur->val);
			cur = cur->next;
		}
		printf("\n");
		while (tail) {
			temp = head->next;
			head->next = tail;
			tail = tail->next;
			head = head->next;
			head->next = temp;
			head = head->next;
		}
    }
};

int main() {
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	ListNode *l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	Solution sol;

	ListNode *cur = l1;
	while (cur) {
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
	sol.reorderList(l1);

	cur = l1;
	while (cur) {
		printf("%d ", cur->val);
		cur = cur->next;
	}
}
