class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;

        long long int divider = 1;

        while(x >= divider*10){
            divider *= 10;
        }

        while(x){
            int right = x % 10;
            int left = x / divider;

            if(left != right)
                return false;

            // remove left-most digit using divider, and right-most digit using 10
            x = (x % divider) / 10;

            // get rid of two digits of the divider everytime two values are compared
            divider /= 100;
        }
        return true;
    }
};