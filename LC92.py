# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        l=[]
        temp2=head
        temp=head
        while(temp):
            l.append(temp.val)
            temp=temp.next
        print(l)
        l2=[]
        for i in range(len(l)):
            if i+1<left or i+1>right:
                continue
            else:
                l2.append(l[i])
        l2=l2[::-1]
        l[left-1:right]=l2[:]
        print(l)
        for i in range(len(l)):
            temp2.val=l[i]
            temp2=temp2.next
        return head
