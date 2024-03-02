class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if('inf' in s or 'Infinity' in s or 'nan' in s):
            return False
        try:
            x=float(s)

            return True
        except:
            return False
