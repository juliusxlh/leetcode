class Solution {
public:    
    void dfs(int deep,int pre,vector<int>& nums)
    {
        ret.push_back(ans);
        for (int i=pre+1;i!=maxn;i++)
        {
            if (!f[i]){
                f[i]=true;
                ans.push_back(nums[i]);
                dfs(deep+1,i,nums);
                ans.pop_back();
                f[i]=false;
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ret.clear();
        ans.clear();
        memset(f,0,sizeof(f));
        maxn = nums.size();
        dfs(0,-1,nums);
        return ret;
    }
    vector<int> ans;
    vector<vector<int>> ret;
    bool f[1000];
    int maxdeep;
    int maxn;
};
