class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;

        // Step 1: Prefix sum of each row
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        // Step 2: Fix two columns, and treat each row as a 1D array
        for (int startCol = 0; startCol < n; ++startCol) {
            for (int endCol = startCol; endCol < n; ++endCol) {
                unordered_map<int, int> sumCount;
                sumCount[0] = 1;
                int currSum = 0;

                for (int row = 0; row < m; ++row) {
                    int rowSum = matrix[row][endCol];
                    if (startCol > 0) {
                        rowSum -= matrix[row][startCol - 1];
                    }

                    currSum += rowSum;

                    if (sumCount.find(currSum - target) != sumCount.end()) {
                        result += sumCount[currSum - target];
                    }

                    sumCount[currSum]++;
                }
            }
        }

        return result;
    }
};
