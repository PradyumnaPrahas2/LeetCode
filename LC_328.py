class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        odd=[]
        even=[]
        temp=head
        temp2=head
        i=1
        while(temp):
            if(i%2==0):
                even.append(temp.val)
            else:
                odd.append(temp.val)
            temp=temp.next
            i=i+1
        while(temp2):
            for i in odd:
                temp2.val=i
                temp2=temp2.next
            for i in even:
                temp2.val=i
                temp2=temp2.next
        return head
