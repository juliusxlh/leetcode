class Solution {
public:
    void dfs(int deep)
    {
        if (deep==m){
            ret.push_back(q);
            return;
        }
        for (int i=0;i!=m;i++){
            if (query(deep,i)){
                cover(deep,i);
                q[deep][i]='Q';
                dfs(deep+1);
                q[deep][i]='.';
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
    
    vector<vector<string>> solveNQueens(int n) {
        memset(flag,0,sizeof(flag));
        q.clear();
        m=n;
        string tmp(n,'.');
        for (int i=0;i!=n;i++) q.push_back(tmp);
        dfs(0);
        return ret;
    }
private:
    vector<string> q;
    vector<vector<string>> ret;
    bool flag[3][100];
    int m;
};
