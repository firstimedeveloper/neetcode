class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev;
        ListNode *temp;
        
    
        prev = NULL;
        while (head->next) {
            temp = head->next;
            head->next = prev;
            head = temp;
        }

        return head;
    }
};


