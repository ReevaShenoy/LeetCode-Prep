class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        int i = 0;

        while(carry){
            if(i < digits.size()){
                if(digits[i] == 9){
                    digits[i] = 0; // with a carry of 1
                }
                else{
                    digits[i]++;
                    carry = 0; // no carry
                }
            }
            else{
                digits.push_back(1); // append 1
                carry = 0;
            }
            i++;
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};