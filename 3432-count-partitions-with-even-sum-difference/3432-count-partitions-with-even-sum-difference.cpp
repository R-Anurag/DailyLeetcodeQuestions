class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        vector<int> cummulativeSum(n);
        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
            cummulativeSum[i] = totalSum;
        }

        int countPartitions = 0;
        for (int i = 1; i < n; ++i) {
            int sumLeft = cummulativeSum[i-1];
            int sumRight = totalSum - sumLeft;

            if (!((sumLeft - sumRight)%2)) countPartitions++;
        }

        return countPartitions++;
    }
};