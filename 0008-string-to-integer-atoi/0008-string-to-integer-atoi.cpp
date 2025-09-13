class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int n = str.size();

        // Step 1: skip leading spaces
        while (i < n && str[i] == ' ') {
            i++;
        }

        // Step 2: handle sign
        int sign = 1;
        if (i < n && (str[i] == '-' || str[i] == '+')) {
            if (str[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Step 3: convert digits
        long ans = 0;
        for (; i < n; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                int d = str[i] - '0';
                ans = ans * 10 + d;

                // Step 4: check overflow
                if (ans * sign > INT_MAX) return INT_MAX;
                if (ans * sign < INT_MIN) return INT_MIN;
            } else {
                break; // stop at first non-digit
            }
        }

        return (int)(ans * sign);
    }
};