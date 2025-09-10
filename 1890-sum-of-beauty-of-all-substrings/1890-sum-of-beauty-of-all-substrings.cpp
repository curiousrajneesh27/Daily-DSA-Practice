class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int minVal = getMin(freq);
                int maxVal = getMax(freq);

                int beauty = maxVal - minVal;
                ans += beauty;
            }
        }
        return ans;
    }

    static int getMax(int freq[]) {
        int maxVal = INT_MIN;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                maxVal = max(maxVal, freq[i]);
        }
        return maxVal;
    }

    static int getMin(int freq[]) {
        int minVal = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                minVal = min(minVal, freq[i]);
        }
        return minVal;
    }
};
