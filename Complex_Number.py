class Solution(object):
    def complexNumberMultiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1 = num1
        num2 = num2
        carry1=0
        carry1in=0
        carry2=0
        carry2in=0
        if(num1[0]=='-'):
            carry1=1
            num1=num1[1:]
        if(num2[0]=='-'):
            carry2=1
            num2=num2[1:]
        # l1=num1.split('-')
        # carry1in=1
        # if(len(l1)==1):
        #     l1=num1.split('+')
        #     carry1in=0
        # l2=num2.split('-')
        # carry2in=1
        # if(len(l2)==1):
        #     l2=num2.split('+')
        #     carry2in=0'
        l1=num1.split('+')
        l2=num2.split('+')
        if(carry1==1):
            l1[0]='-'+l1[0]
        # if(carry1in):
        #     l1[1]='-'+l1[1]
        if(carry2==1):
            l2[0]='-'+l2[0]
        print(carry1,carry1in,carry2,carry2in)
        answer=(str(int(l1[0])*int(l2[0])-1*(int(l1[1][:-1])*int(l2[1][:-1])))+'+'+str(int(l1[0])*int(l2[1][:-1])+int(l1[1][:-1])*int(l2[0]))+'i')
        print(answer)
        return answer
    
