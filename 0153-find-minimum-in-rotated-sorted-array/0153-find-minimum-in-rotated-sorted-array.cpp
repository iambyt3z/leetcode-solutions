class Solution {
public:
    int findPivot(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<=r) {
            if(nums[l] <= nums[r])
                return l;

            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r])
                l = mid+1;
            else
                r=mid;
        }
        return -1;
    }

    int findMin(vector<int>& nums) {
        int pivot = findPivot(nums);
        return nums[pivot];
    }
};