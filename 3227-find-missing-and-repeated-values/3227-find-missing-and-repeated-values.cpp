class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long totalNums = 1LL * n * n; // total numbers from 1 to n²

        long long expectedSum = totalNums * (totalNums + 1) / 2;
        long long expectedSqSum = totalNums * (totalNums + 1) * (2 * totalNums + 1) / 6;

        long long sum = 0, sumSq = 0;
        for (auto &row : grid) {
            for (int num : row) {
                sum += num;
                sumSq += 1LL * num * num;
            }
        }

        // Let repeating = x, missing = y
        long long diff = sum - expectedSum;         // x - y
        long long sqDiff = sumSq - expectedSqSum;   // x² - y² = (x - y)(x + y)

        long long sumXY = sqDiff / diff;            // x + y

        long long x = (diff + sumXY) / 2;           // repeating
        long long y = x - diff;                     // missing

        return {(int)x, (int)y};
    }
};
