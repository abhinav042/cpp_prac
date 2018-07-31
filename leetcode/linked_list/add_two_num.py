# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
        
class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry_over = 0
        ans = ""
        head = ListNode(0)
        curr = head
        while l1 != None and l2 != None:
            sum_val = l1.val + l2.val + carry_over
            digit = sum_val % 10
            carry_over = int (sum_val / 10)
            head.next = ListNode(digit)
            head = head.next
            l1 = l1.next
            l2 = l2.next
        if (l1 == None and l2 != None):
            while l2 != None:
                sum_val = l2.val + carry_over
                digit = sum_val % 10
                carry_over = int (sum_val / 10)
                head.next = ListNode(digit)
                head = head.next
                l2 = l2.next
        elif (l2 == None and l1 != None):
            while l1 != None:
                sum_val = l1.val + carry_over
                digit = sum_val % 10
                carry_over = int (sum_val / 10)
                head.next = ListNode(digit)
                head = head.next
                l1 = l1.next  
        if carry_over != 0:
            head.next = ListNode(carry_over)
            head = head.next
        return curr.next