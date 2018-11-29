class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        roxH.clear();
        maxArea = 0;
        for (int i=0;i!=matrix.size();i++)
        {
            roxH.push_back(vector<int>());
            for (int j=0;j!=matrix[0].size();j++){
                if (matrix[i][j]=='1'){
                    if (i!=0) 
                        roxH[i].push_back(roxH[i-1][j]+1);
                    else
                        roxH[i].push_back(1);
                } else{
                    roxH[i].push_back(0);
                }
            }
        }
        for (int i=0;i!=matrix.size();i++)
        {
            stack<int> s;
            for (int j=0;j<=matrix[0].size();j++){
                int h = (j == matrix[0].size() ? 0 : roxH[i][j]);
                if (s.empty()||h>=roxH[i][s.top()]){
                    s.push(j);
                }else{
                    int tp = s.top();
                    s.pop();
                    maxArea = max(maxArea, roxH[i][tp] * (s.empty() ? j : j - 1 - s.top()));
                    j--;
                }
            }
        }
        return maxArea;
    }
    vector<vector<int>> roxH;
    int maxArea;
};
