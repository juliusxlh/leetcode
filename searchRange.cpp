class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return vector<int>(2,-1);
        vector<int> ret;
        int l=0;
        int r=nums.size()-1;
        while (l<r)
        {
            int mid =(l+r+1)/2;
            if (nums[mid]<target){
                l=mid;
            } else{
                r=mid-1;
            }
        }
        if (nums[l]==target) ret.push_back(0);
        else if ((l+1>=nums.size() || nums[l+1]!=target)) return vector<int>(2,-1);
        else ret.push_back(l+1);
        l=0;
        r=nums.size()-1;
        while (l<r)
        {
            int mid =(l+r)/2;
            if (nums[mid]>target){
                r=mid;
            } else{
                l=mid+1;
            }
        }
        if (nums[r]==target) ret.push_back(nums.size()-1);
        else if ((r-1<0 || nums[r-1]!=target)) return vector<int>(2,-1);
        else ret.push_back(r-1);
        return ret;
    }
    
};
