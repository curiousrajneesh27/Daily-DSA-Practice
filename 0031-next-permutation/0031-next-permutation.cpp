class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n = nums.size();
        int i = nums.size() - 2;

        while(i >= 0 && nums [i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;

            while (j >= 0 && nums [j] <= nums[i]) {
            j--;
        }

        swap(nums[i], nums[j]);
        } 

        reverse(nums.begin() + i + 1, nums.end());
    }
};

// int main() {
//     vector<int> nums = {4, 2, 0, 2, 3, 2, 0};

//     Solution().nextPermutation(nums);


//     cout << "final rwsult: ";
//     for (int num : nums) cout << num;
//     cout <<  endl;

//     return 0;