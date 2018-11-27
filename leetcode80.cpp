class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int pre = nums[0];
        int sum = 1;
        int st = 1;
        for (int i=1;i<nums.size();i++){
            if (nums[i]==pre){
                sum++;
                if (sum<=2){
                    nums[st++]=nums[i];
                }
            } else {
                pre = nums[i];
                sum = 1;
                nums[st++]=nums[i];
            }
        }
        nums.erase(nums.begin()+st,nums.end());
        return nums.size();
    }
};
