class Solution {
public:
    set<vector<int>> s;

    void getAllCombinations(vector<int>& arr, int idx, int target,
                            vector<vector<int>> &ans, vector<int> &combin) {

        if (idx == arr.size() || target < 0) {
            return;
        }

        if (target == 0) {
            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        // pick current element
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx + 1, target - arr[idx], ans, combin);
        getAllCombinations(arr, idx, target - arr[idx], ans, combin);
        combin.pop_back();

        // skip current element
        getAllCombinations(arr, idx + 1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(candidates, 0, target, ans, combin);

        return ans;
    }
};