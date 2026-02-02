class Solution {
public:
    void help(int i, int k, int sumTillNow, int n,
              vector<int>& subSet, vector<vector<int>>& ans) {

        // base cases
        if (k == 0) {
            if (sumTillNow == n) {
                ans.push_back(subSet);
            }
            return;
        }

        if (i > 9 || sumTillNow > n) return;

        // pick the ith element
        sumTillNow += i;
        subSet.push_back(i);
        help(i + 1, k - 1, sumTillNow, n, subSet, ans);
        subSet.pop_back();
        sumTillNow -= i;

        // ignore the ith element
        help(i + 1, k, sumTillNow, n, subSet, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subSet;
        help(1, k, 0, n, subSet, ans);
        return ans;
    }
};
