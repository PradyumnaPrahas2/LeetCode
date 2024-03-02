class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        l=[]
        temp2=head
        temp=head
        while(temp):
            l.append(temp.val)
            temp=temp.next
        for i in range(0,len(l),k):
            if(i+k>len(l)):
                break
            else:
                x=l[i:i+k]
                l[i:i+k]=x[::-1]
        print(l)
        for i in range(len(l)):
            temp2.val=l[i]
            temp2=temp2.next
        return head
