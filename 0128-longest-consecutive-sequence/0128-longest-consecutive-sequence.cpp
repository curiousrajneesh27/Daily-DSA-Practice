class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for(auto it : st) {
            if(st.find(it - 1) == st.end()) { // only start counting if it's the beginning of a sequence
                int cnt = 1;
                int x = it;

                while(st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
