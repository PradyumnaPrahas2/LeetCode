class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        l=[]
        temp=head
        temp2=head
        while(temp):
            l.append(temp.val)
            temp=temp.next
        if(len(l)%2==0):
            temp2=head
            x=l[:len(l)//2]
            y=l[len(l)//2:]
            y=y[::-1]
            for i in range(len(x)):
                temp2.val=x[i]
                temp2=temp2.next
                temp2.val=y[i]
                temp2=temp2.next
        else:
            temp2=head
            x=l[:len(l)//2+1]
            y=l[len(l)//2+1:]
            y=y[::-1]
            for i in range(len(y)):
                temp2.val=x[i]
                temp2=temp2.next
                temp2.val=y[i]
                temp2=temp2.next
            temp2.val=x[-1]
        return head
