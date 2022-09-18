/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
		Node *ret, *cur, *temp, *cpy;

		cur = head;
		while (cur) {
			temp = new Node(cur->val); //cpy of cur Node
			temp->next = cur->next;
            temp->random = NULL;
			cur->next = temp;
			cur = cur->next->next;
		}
        cur = head;
		while (cur) {
			printf("%d ", cur->val);
			cur = cur->next;
		}
        printf("\n");
		cur = head;
		while (cur) {
			if (cur->random)
				cur->next->random = cur->random->next;
			cur = cur->next->next;
		}
		
		ret = new Node(0);
		cur = ret;
        cpy = head;
		while (cpy) {
			cur->next = cpy->next;
			cur = cur->next;

			cpy->next = cpy->next->next;
			cpy = cpy->next;
		}
		return ret->next;
    }
};
