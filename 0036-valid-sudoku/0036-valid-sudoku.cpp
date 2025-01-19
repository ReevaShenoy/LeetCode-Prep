class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> squares[3][3];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char current = board[r][c];
                if (current == '.') continue;

                // duplicates
                if (rows[r].count(current) || cols[c].count(current) || squares[r / 3][c / 3].count(current)) {
                    return false;
                }

                rows[r].insert(current);
                cols[c].insert(current);
                squares[r / 3][c / 3].insert(current);
            }
        }
        return true;
    }
};