class Solution {
public:
    void dfs(int deep)
    {
        if (deep == num.size()){
            ret.push_back(tmp);
            return;
        }
        int preint = -1;
        bool flag = false;
        for (int i=0; i!=num.size(); i++){
            if (!f[i] && !(flag && preint == num[i])){
                flag = true;
                preint = num[i];
                f[i] = true;
                tmp.push_back(num[i]);
                dfs(deep+1);
                tmp.pop_back();
                f[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        num.assign(nums.begin(),nums.end());
        memset(f,0,sizeof(bool)*10000);
        dfs(0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> tmp;
    vector<int> num;
    bool f[10000];
};