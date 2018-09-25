class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(sudoku, 0,sizeof(bool)*3*9*9);
        for (int i=0;i!=9;i++){
            for (int j=0;j!=9;j++){
                if (board[i][j]!='.'){
                    int tmp = board[i][j] - '0' - 1;
                    if (sudoku[0][i][tmp]) return false;
                    if (sudoku[1][j][tmp]) return false;
                    if (sudoku[2][i/3*3+j/3][tmp]) return false;
                    sudoku[0][i][tmp] = true;
                    sudoku[1][j][tmp] = true;
                    sudoku[2][i/3*3+j/3][tmp] = true;
                }
            }
        }
        return true;
    }
private:
    bool sudoku[3][9][9];
};