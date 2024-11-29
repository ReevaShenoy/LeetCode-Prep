class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result = []
        digitToChar = {
            "2": "abc", "3": "def",
            "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs",
            "8": "tuv", "9": "wxyz"
        }

        def backtrack(i, currentStr):
            if len(currentStr) == len(digits):
                result.append(currentStr)
                return
            
            for x in digitToChar[digits[i]]: # each string value in the dictionary
                backtrack(i+1, currentStr + x)

        if digits: # shouldn't be empty
            backtrack(0, "")

        return result