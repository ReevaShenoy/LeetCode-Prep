class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> result(n1+n2, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i1=0; i1<n1; i1++){
            for(int i2=0; i2<n2; i2++){
                int digit = (num1[i1] - '0') * (num2[i2] - '0');
                result[i1+i2] += digit;
                result[i1+i2+1] += result[i1+i2]/10; // carry
                result[i1+i2] = result[i1+i2]%10;
            }
        }

        while(result.size() > 1 && result.back() == 0)
            result.pop_back();

        reverse(result.begin(), result.end());
        string final;
        for(int x:result)
            final += (x + '0');

        return final;
    }
};