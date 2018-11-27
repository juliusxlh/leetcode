class Solution {
public:    
    void dfs(int deep,int pre)
    {
        if (deep==maxdeep){
            ret.push_back(ans);
        }
        for (int i=pre+1;i<=maxn;i++)
        {
            if (!f[i]){
                f[i]=true;
                ans.push_back(i);
                dfs(deep+1,i);
                ans.pop_back();
                f[i]=false;
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        ret.clear();
        ans.clear();
        if (k==0) return ret;
        memset(f,0,sizeof(f));
        maxdeep = k;
        maxn = n;
        dfs(0,0);
        return ret;
    }
    vector<int> ans;
    vector<vector<int>> ret;
    bool f[1000];
    int maxdeep;
    int maxn;
};
