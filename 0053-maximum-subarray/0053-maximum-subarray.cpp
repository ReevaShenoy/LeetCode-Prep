class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int currentSum = 0;

        for(int x: nums){
            if(currentSum < 0){
                currentSum = 0;
            }
            currentSum += x;
            maxSub = max(maxSub, currentSum);
        }
        
        return maxSub;
    }
};