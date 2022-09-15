// iterative version
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev;
        ListNode *temp;
        
    
        prev = NULL;
        while (head) {
            temp = head->next; // save next value to temp
            head->next = prev; // cur head's next is set to prev
            prev = head; // prev is updated to head
            head = temp; // head = head->next
        }
        return prev;
    }
};
// recursive version, same idea as iterative
class Solution {
public:
    ListNode* recur(ListNode* cur, ListNode *prev) {
        if (!cur)
            return prev;
        ListNode *temp = cur->next;
        cur->next = prev;
        return recur(temp, cur);
    }
    
    ListNode* reverseList(ListNode* head) {
      return recur(head, NULL);
    }
};
