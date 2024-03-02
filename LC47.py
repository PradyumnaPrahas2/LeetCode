from itertools import permutations
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        l=[list(i) for i in permutations(nums,len(nums))]
        res=[]
        for i in l:
            if i not in res:
                res.append(i)
        return res
