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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> found;
        ListNode *ret = new ListNode;
        ListNode *prev;
        
        ret->next = head;
        for (; head != nullptr; head = head->next) {
            if (found.count(head->val)) {
                found[head->val]++;
            } else {
                found[head->val] = 1;
            }
        }
        
        head = ret->next;
        prev = ret;
        for (; head != nullptr; head = head->next) {
            if (found[head->val] > 1) {
                prev->next = head->next;
            } else
                prev = head;
        }
        
        
        
        return ret->next;
    }
};
