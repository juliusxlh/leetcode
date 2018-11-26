class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st=0;
        int ed=nums.size()-1;
        int i=0;
        while(true){
            if (i<st || i >ed || i>=nums.size()) break;
            if (nums[i]==0 && i>st){
                swap(nums[st],nums[i]);
                st++;
            } else if (nums[i]==0) i++;
            if (nums[i]==2 && i<ed){
                swap(nums[ed],nums[i]);
                ed--;
            } else if (nums[i]==2) break;
            if (nums[i]==1) i++;
        }
    }
};
