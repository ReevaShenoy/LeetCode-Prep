class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        w = s.split()

        if w:
            return len(w[-1])
        return 0