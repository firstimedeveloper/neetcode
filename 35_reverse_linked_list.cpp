class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev;
        ListNode *temp;
        
    
        prev = NULL;
        while (head) {
            if (prev)
                printf("%d %d\n", head->val, prev->val);
            temp = head->next; // save next value to temp
            head->next = prev; // cur head's next is set to prev
            prev = head; // prev is updated to head
            head = temp; // head = head->next
        }
        return prev;
    }
};
