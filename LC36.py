import numpy as np
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        def check(l):
            print(l)
            x=l.count('.')-1
            if(x==len(l)):
                return False
            c=set(l)
            print(len(c)+x,len(l))
            if(len(c)+x!=len(l)):
                return False
            return True
        rows=len(board)
        col=len(board[0])
        for i in range(rows):
            if(check(board[i][:])==False):
                return False
        l=np.array(board)
        for i in range(col):
            n=list(l[:,i])
            if(check(n)==False):
                return False
        return True
        
