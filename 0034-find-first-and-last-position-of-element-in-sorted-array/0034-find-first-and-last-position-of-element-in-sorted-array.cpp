class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        return {left, right};
    }

private:
    int binarySearch(vector<int>& nums, int target, bool leftBias) {
        int l = 0;
        int r = nums.size() - 1;
        int i = -1;

        while (l <= r) {
            int m = l + (r-l)/2;
            if(target > nums[m])
                l = m+1;
            else if(target < nums[m])
                r = m-1;
            else{
                i = m;
                if (leftBias)
                    r = m-1;
                else
                    l = m+1;
            }
        }
        return i;
    }
};