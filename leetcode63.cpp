class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size()==0 || obstacleGrid[0].size()==0) return 0;
        memset(answer,0,sizeof(answer));
        if (obstacleGrid[0][0]==1) return 0;
        answer[1][1]=1;
        for (int i=1;i<=obstacleGrid.size();i++)
        {
            for (int j=1;j<=obstacleGrid[0].size();j++)
            {
                if (obstacleGrid[i-1][j-1]==0){
                    if (i!=1 || j!=1) answer[i][j]=answer[i-1][j]+answer[i][j-1];
                }
            }
        }
        return answer[obstacleGrid.size()][obstacleGrid[0].size()];
    }
    int answer[200][200];
};
