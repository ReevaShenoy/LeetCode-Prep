class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False

        divider = 1

        # if x = 1551, then divider has to be 1000
        while x >= divider*10:
            divider *= 10

        while x:
            # compare left most and right most values
            right = x % 10
            left = x // divider

            if left != right:
                return False
            
            # remove the compared values
            # remove the left most using the divider, and the right most using 10
            x = (x % divider) // 10

            # remove two digits from divider everytime left-most and right-most values are compared
            divider /= 100
        
        return True