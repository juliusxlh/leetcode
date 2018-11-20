class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(answer,0,sizeof(answer));
        answer[1][1]=1;
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (i!=1 || j!=1) answer[i][j]=answer[i-1][j]+answer[i][j-1];
            }
        }
        return answer[m][n];
    }
    int answer[200][200];
};
