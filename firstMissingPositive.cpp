class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0;i!=nums.size();i++){
            if (nums[i]>0 && nums[i]<=nums.size() && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]){
                int x = nums[i]-1;
                int y = i;
                while (true){
                    int tmp = nums[x];
                    nums[x] = nums[y];
                    nums[y] = tmp;
                    if (nums[y]>0 && nums[y]<=nums.size() && nums[y]!=y+1 && nums[nums[y]-1]!=nums[y]){
                        x = nums[y]-1;
                    } else break;
                }
            }
        }
        for (int i=0;i!=nums.size();i++){
            if (i+1!=nums[i]) return i+1;
        }
        return nums.size()+1;
    }
};
