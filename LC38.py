class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        def count(k,n):
            if(n==1):
                return k
            else:
                l=list(k)
                i=0
                k=''
                l.append(0)
                while i<len(l)-1:
                    c=1
                    x=l[i]
                    while(l[i+1]==l[i]):
                        c+=1
                        i+=1
                    k=k+str(c)+str(x)
                    i+=1
                print(k)
                return count(k,n-1)
        return count('1',n)
