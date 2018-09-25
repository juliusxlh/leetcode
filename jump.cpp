class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int ans[100000];
        memset(ans,0,sizeof(int)*100000);
        for (int i=0;i!=len;i++){
            int sc = min(len-1, i+nums[i]);
            for (int j=sc;j!=i;j--){
                if (ans[j]) break;
                ans[j] = ans[i]+1;
            }
        }
        return ans[nums.size()-1];
    }
};