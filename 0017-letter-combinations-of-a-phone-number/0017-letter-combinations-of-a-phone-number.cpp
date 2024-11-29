class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty())
            return result;

        unordered_map<char, string> digitToChar = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        string currentStr;

        backtrack(0, digits, digitToChar, currentStr, result);

        return result;
    }

private:
    void backtrack(int i, const string& digits, const unordered_map<char, string>& digitToChar, 
                   string& currentStr, vector<string>& result) {

        if (currentStr.size() == digits.size()) {
            result.push_back(currentStr);
            return;
        }

        for (char ch : digitToChar.at(digits[i])) {
            currentStr.push_back(ch);
            backtrack(i + 1, digits, digitToChar, currentStr, result);
            currentStr.pop_back();
        }
    }
};
