class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        l=[]
        temp=head
        while(temp):
            l.append(temp.val)
            temp=temp.next
        initial=0
        print(l)
        for i in range(len(l)):
            if(l[i]<x):
                ans=l[i]
                l.pop(i)
                l.insert(initial,ans)
                initial+=1
        print(l)    
        temp2=head
        for i in l:
            temp2.val=i
            temp2=temp2.next
        return head
