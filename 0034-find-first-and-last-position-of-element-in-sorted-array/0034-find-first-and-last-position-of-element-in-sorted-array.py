class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = self.binarySearch(nums, target, True)
        right = self.binarySearch(nums, target, False)
        return [left, right]
        
    # leftBias can be either true or false
    # if it's false, then it's rightBias -> look for the right-most index
    def binarySearch(self, nums, target, leftBias):
        l = 0
        r = len(nums)-1
        i = -1
        while l<=r:
            m = (l+r)//2
            if target > nums[m]:
                # search to the right
                l = m+1
            elif target < nums[m]:
                # search to the left
                r = m-1
            else:
                i = m
                if leftBias:
                    r = m-1
                else:
                    l = m+1
        return i
