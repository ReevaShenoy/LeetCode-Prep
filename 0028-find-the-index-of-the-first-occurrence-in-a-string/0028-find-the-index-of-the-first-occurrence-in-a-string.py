class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        
        for i in range(len(haystack) + 1 - len(needle)):
            # does ever character of the needle match with a substring in the haystack
            for j in range(len(needle)):
                # i is the starting index, j acts as the increment
                if haystack[i+j] != needle[j]:
                    break
                if j == len(needle)-1:
                    return i
        
        return -1