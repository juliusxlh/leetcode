class Solution {
public:
    void dfs(int deep)
    {
        if (deep==m){
            ++ans;
            return;
        }
        for (int i=0;i!=m;i++){
            if (query(deep,i)){
                cover(deep,i);
                dfs(deep+1);
                uncover(deep,i);
            }
        }
    }
    
    bool query(int x,int y)
    {
        if (flag[0][y]) return false;
        if (flag[1][x+y]) return false;
        if (flag[2][m-1-x+y]) return false;
        return true;
    }
    
    void cover(int x,int y)
    {
        flag[0][y]=true;
        flag[1][x+y]=true;
        flag[2][m-1-x+y]=true;
    }
    
    void uncover(int x, int y)
    {
        flag[0][y]=false;
        flag[1][x+y]=false;
        flag[2][m-1-x+y]=false;
    }
    
    int totalNQueens(int n) {
        ans=0;
        memset(flag,0,sizeof(flag));
        m=n;
        dfs(0);
        return ans;
    }
private:
    int ans;
    bool flag[3][100];
    int m;
};
