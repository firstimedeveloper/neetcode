class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def recur(cur, prev):
            if not cur:
                return prev
            temp = cur.next
            cur.next = prev
            prev = cur
            return recur(temp, prev)
            
        return recur(head, None)
        
