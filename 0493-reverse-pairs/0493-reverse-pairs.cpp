class Solution {
public:
    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        int count = mergeSort(arr, low, mid) + mergeSort(arr, mid + 1, high);

        // Count reverse pairs
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int left = low;
        right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);
        for (int i = low; i <= high; i++) arr[i] = temp[i - low];

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, (int)nums.size() - 1);
    }
};
