# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        l = head
        r = head
        
        while l and r:        
            l = l.next
            if not l:
                return False
            if r and r.next and r.next:
                r = r.next.next
            else:
                return False
            if l == r:
                return True
        return False
