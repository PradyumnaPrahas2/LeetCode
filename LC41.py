class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i=1
        nums=set(nums)
        while(1):
            if(i not in nums):
                return i
            i+=1
