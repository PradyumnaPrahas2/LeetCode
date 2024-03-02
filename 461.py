class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        x=bin(x)
        y=bin(y)
        x=x[2:]
        y=y[2:]
        if(len(x)>len(y)):
            a=len(x)-len(y)
            s=''
            for i in range(a):
                s=s+'0'
            s=s+y
            y=s
        elif(len(x)<len(y)):
            a=len(y)-len(x)
            s=''
            for i in range(a):
                s=s+'0'
            s=s+x
            x=s
        count=0
        for i in range(len(x)):
            if(x[i]!=y[i]):
                count+=1
        return count
       
