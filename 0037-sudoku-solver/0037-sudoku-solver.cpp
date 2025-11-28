class Solution {
public:

// Optimal Sudoku solver using MRV heuristic:
// Always pick the empty cell with minimum valid choices.
    bool solveOptimal(vector<vector<char>>& board,
                    vector<vector<bool>>& rowUsed,
                    vector<vector<bool>>& colUsed,
                    vector<vector<bool>>& boxUsed) 
    {
        int targetRow = -1, targetCol = -1;
        int minOptions = 10;

        // Find the cell having minimum number of valid digits (MRV)
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] == '.') {
                    int boxId = (r / 3) * 3 + (c / 3);
                    int count = 0;

                    for(char digit = '1'; digit <= '9'; digit++) {
                        int val = digit - '0';
                        if(!rowUsed[r][val] &&
                        !colUsed[c][val] &&
                        !boxUsed[boxId][val]) count++;
                    }

                    if(count < minOptions) {
                        minOptions = count;
                        targetRow = r;
                        targetCol = c;
                    }
                }
            }
        }

        if(targetRow == -1) return true; // All filled
        int r = targetRow, c = targetCol;
        int boxId = (r / 3) * 3 + (c / 3);
        for(char digit = '1'; digit <= '9'; digit++) {
            int val = digit - '0';

            if(!rowUsed[r][val] &&
            !colUsed[c][val] &&
            !boxUsed[boxId][val]) 
            {
                board[r][c] = digit;

                rowUsed[r][val] = colUsed[c][val] = boxUsed[boxId][val] = true;

                if(solveOptimal(board, rowUsed, colUsed, boxUsed)) return true;

                board[r][c] = '.';
                rowUsed[r][val] = colUsed[c][val] = boxUsed[boxId][val] = false;
            }
        }

        return false;
    }


    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowUsed(9, vector<bool>(10,false));
        vector<vector<bool>> colUsed(9, vector<bool>(10,false));
        vector<vector<bool>> boxUsed(9, vector<bool>(10,false));

        // Initial fill
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] != '.') {
                    int val = board[r][c] - '0';
                    rowUsed[r][val] = colUsed[c][val] = true;
                    boxUsed[(r/3)*3 + (c/3)][val] = true;
                }
            }
        }

        solveOptimal(board, rowUsed, colUsed, boxUsed);
    }
};
