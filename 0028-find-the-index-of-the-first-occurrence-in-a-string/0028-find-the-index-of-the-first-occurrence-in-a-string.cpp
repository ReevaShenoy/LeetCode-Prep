class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        
        for (int i = 0; i <= (int)haystack.length() - (int)needle.length(); ++i) {
            if (haystack.substr(i, needle.length()) == needle)
                return i;
        }

        return -1;
    }
};