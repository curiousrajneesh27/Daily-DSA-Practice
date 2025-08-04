class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = nums[0];

        for(int val : nums){
            currentSum += val;
            maxSum = max(currentSum, maxSum);

            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};