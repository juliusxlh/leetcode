class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0) return -1;
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while (l<=r)
        {
            mid = (l+r)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid]>=nums[r] && nums[mid]>=nums[l]){
                if (target<=nums[mid] && target>=nums[l]){
                    r=mid-1;
                    continue;
                } else{
                    l=mid+1;
                    continue;
                }
            }else{
                if (target>=nums[mid] && target<=nums[r]){
                    l=mid+1;
                    continue;
                }else{
                    r=mid-1;
                    continue;
                }
            }
        }
        return -1;
    }
};
