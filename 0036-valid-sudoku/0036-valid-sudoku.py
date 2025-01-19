class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = collections.defaultdict(set)
        rows = collections.defaultdict(set)
        squares = collections.defaultdict(set)    # key = (row/3, col/3)

        for r in range(9):
            for c in range(9):
                # empty cell
                if board[r][c] == ".":
                    continue
                # duplicate
                if(board[r][c] in rows[r]
                    or board[r][c] in cols[c]
                    or board[r][c] in squares[(r//3, c//3)]):
                        return False
                
                rows[r].add(board[r][c])
                cols[c].add(board[r][c])
                squares[(r//3, c//3)].add(board[r][c])
        return True