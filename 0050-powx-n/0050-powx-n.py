class Solution:
    def myPow(self, x: float, n: int) -> float:
        def func(x, n):
            if x==0:
                return 0
            if n==0:
                return 1

            ans = func(x, n//2)
            ans *= ans
            
            if n%2==1:
                return x*ans
            else:
                return ans
        
        ans = func(x, abs(n))
        if n>=0:
            return ans
        else:
            return 1/ans