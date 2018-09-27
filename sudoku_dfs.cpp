class Solution {
public:
    struct candidate;
    static bool cmp(candidate x, candidate y)
    {
        return x.probability_list.size()< y.probability_list.size();
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(sudoku,0,sizeof(sudoku));
        memset(sudoku_a,0,sizeof(sudoku_a));
        candidate_list.clear();
        empty = 0;
        for (int i=0;i!=9;i++)
        {
            for (int j=0;j!=9;j++)
            {
                if (board[i][j] != '.'){
                    sudoku_a[i][j] = board[i][j] - '0';
                    cover(i,j,sudoku_a[i][j]-1);
                }
            }
        }
        for (int i=0;i!=9;i++)
        {
            for (int j=0;j!=9;j++)
            {
                if (!(sudoku[0][i]&(1<<j))){
                    ++empty;
                    int sum=0;
                    candidate tmp;
                    tmp.x=i;
                    tmp.y=j;
                    for (int k=0;k!=9;k++){
                        if (query(i,j,k))
                            tmp.probability_list.push_back(k);
                    }
                    candidate_list.push_back(tmp);
                }
            }
        }
        sort(candidate_list.begin(),candidate_list.end(),cmp);
        dfs(0);
        for (int i=0;i!=9;i++){
            for (int j=0;j!=9;j++){
                if (board[i][j]=='.') board[i][j] = '0'+sudoku_a[i][j];
            }
        }
    }
    bool dfs(int deep)
    {
        if (deep == empty) return true;
        auto iter = candidate_list[deep];
        for (auto ix=iter.probability_list.begin();ix!=iter.probability_list.end();ix++){
            if (query(iter.x,iter.y,*ix)){
                cover(iter.x,iter.y,*ix);
                sudoku_a[iter.x][iter.y] = *ix + 1;
                if (dfs(deep+1)) return true;
                uncover(iter.x,iter.y,*ix);
            }
        }
        return false;
    }
    void cover(int x, int y, int z)
    {
        sudoku[0][x]|=(1<<y);
        sudoku[1][x]|=(1<<z);
        sudoku[2][y]|=(1<<z);
        sudoku[3][x/3*3+y/3]|=(1<<z);
    }
    void uncover(int x, int y, int z)
    {
        sudoku[0][x]&=(~(1<<y));
        sudoku[1][x]&=(~(1<<z));
        sudoku[2][y]&=(~(1<<z));
        sudoku[3][x/3*3+y/3]&=(~(1<<z));       
    }
    bool query(int x, int y, int z)
    {
        if (sudoku[0][x]&(1<<y)) return false;
        if (sudoku[1][x]&(1<<z)) return false;
        if (sudoku[2][y]&(1<<z)) return false;
        if (sudoku[3][x/3*3+y/3]&(1<<z)) return false; 
        return true;
    }
    struct candidate
    {
        vector<int> probability_list;
        int x;
        int y;
    };
private:
    int sudoku[4][9];
    int sudoku_a[9][9];
    int empty=0;
    vector<candidate> candidate_list;
};
