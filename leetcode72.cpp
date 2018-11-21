class Solution {
public:
    int minDistance(string word1, string word2) {
        int* ans = (int*)malloc((word2.size()+1)*2*sizeof(int));
        memset(ans,0,(word2.size()+1)*2*sizeof(int));
        for (int j=1;j<=word2.size();j++) ans[j]=j;
        ans[0]=0;
        ans[word2.size()+1]=0;
        for (int i=1;i<=word1.size();i++){
            int t=i%2;
            int p=(i-1)%2;
            ans[t*(word2.size()+1)]=i;
            for (int j=1;j<=word2.size();j++){
                int n=t*(word2.size()+1)+j;
                int m=p*(word2.size()+1)+j;
                if (word1[i-1]==word2[j-1]) ans[n]=ans[m-1];
                else{
                    ans[n]=min(min(ans[m],ans[n-1]),ans[m-1])+1;
                }
            }
        }
        return ans[word1.size()%2*(word2.size()+1)+(word2.size())];
    }
};
