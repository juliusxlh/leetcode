#include <vector>
#include<queue>

using namespace std;

class Solution {
public:
    Solution(){
        for (int i = 0; i != 324; i++){
            dlx_array[i] = new CircularQueue();
        }
        for (int i = 0; i != 324; i++)
        {
            dlx_array[i]->right = dlx_array[(i + 1) % 324];
            dlx_array[i]->left = dlx_array[(i + 323) % 324];
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        ConstructDLXMap(board);
        Dance(0);
        release_array();
    }
private:
    struct CircularQueue;

    bool Dance(int deep)
    {
        int min = 729;
        
    }

    void InsertUpDownPoint(CircularQueue *up, CircularQueue *down)
    {
        up->column_num += 1;
        up->down->up = down;
        down->down = up->down;
        up->down = down;
        down->up = up;
    }
    void InsertRLPoint(CircularQueue *L, CircularQueue *R){
        L->right->left = R;
        R->right = L->right;
        L->right = R;
        R->left = L;
    }
    void insertDLXPoint(int x,int y,int z)
    {
        CircularQueue *limit1 = new CircularQueue();
        CircularQueue *limit2 = new CircularQueue();
        CircularQueue *limit3 = new CircularQueue();
        CircularQueue *limit4 = new CircularQueue();
        InsertUpDownPoint(dlx_array[x * 9 + y], limit1);
        InsertUpDownPoint(dlx_array[81 + x * 9 + z], limit2);
        InsertUpDownPoint(dlx_array[162 + y * 9 + z], limit3);
        InsertUpDownPoint(dlx_array[243 + (x * 3 + y) * 9 + z], limit4);
        InsertRLPoint(limit1,limit2);
        InsertRLPoint(limit2,limit3);
        InsertRLPoint(limit3,limit4);
    }

    void ConstructDLXMap(vector<vector<char>>& board)
    {
        for (int i = 0; i != 9;i++){
            for (int j = 0; j != 0;j++){
                if (board[i][j]=='.'){
                    insertDLXPoint(i,j,board[i][j]-'0'-1);
                } else{
                    for (int k = 0; k != 9;k++)
                        insertDLXPoint(i, j, k);
                }
            }
        }
    }
    //释放掉map里的资源
    void release_array()
    {
        for (int i = 0; i != 324;i++){
            CircularQueue* tmp = dlx_array[i]->down;
            while (tmp != dlx_array[i]){
                CircularQueue *temp = tmp->down;
                tmp->up->down = tmp->down;
                tmp->down->up = tmp->up;
                delete tmp;
                tmp = temp;
            }
        }       
    }
    // 循环队列
    struct CircularQueue
    {
        CircularQueue *down, *up, *right, *left;
        int column_num;
        CircularQueue()
        {
            down = this;
            up = this;
            right = this;
            left = this;
            column_num = 0;
        }
        /* data */
    };

    CircularQueue* dlx_array[324];
    int ans[81][3];
};

int main()
{

}