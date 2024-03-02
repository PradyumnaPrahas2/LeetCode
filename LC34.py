class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l=[]
        if(target not in nums):
            l=[-1,-1]
            return l
        else:
            x=nums.count(target)
            c=nums.index(target)
            l.append(c)
            l.append(x+c-1)
            return l
        
