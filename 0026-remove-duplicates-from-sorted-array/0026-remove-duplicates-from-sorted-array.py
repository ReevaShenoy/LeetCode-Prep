class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = 1
        # start from index 1 since first element won't be a duplicate
        for r in range(1, len(nums)):
            if nums[r] != nums[r-1]:
                nums[l] = nums[r]
                l += 1
        return l

