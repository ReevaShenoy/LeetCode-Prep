class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # top down memoization => caching

        cache = {}

        def dfs(i, j):

            if (i, j) in cache:
                return cache[(i, j)]

            # out of bounds
            if i >= len(s) and j >= len(p):
                return True
            if j >= len(p):
                return False

            match = i < len(s) and (s[i] == p[j] or p[j]==".")

            # is the next char a star?
            if j+1 < len(p) and p[j+1] == "*":
                cache[(i, j)] = (dfs(i, j+2)    # we dont use the star; we move j forward in the pattern by 2 characters
                                                # c*a*b* => j at c, j+1 is a star, j+2 is the next character
                                or (match and dfs(i+1, j))) # we use the star
                return cache[(i, j)]

            # if there's no star, and there's a match
            if match:
                cache[(i, j)] = dfs(i+1, j+1)
                return cache[(i, j)]

            cache[(i, j)] = False

            # if there's no star, and there's no match
            return False
        
        return dfs(0, 0)