class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long countSmoothDescentPeriods = 0;
        long long contiguousCount = 1;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] == prices[i-1] - 1) ++contiguousCount;
            else {
                countSmoothDescentPeriods += (contiguousCount*(contiguousCount+1))/2;
                contiguousCount = 1;
            }
        }
        countSmoothDescentPeriods += (contiguousCount*(contiguousCount+1))/2;

        return countSmoothDescentPeriods;
    }
};