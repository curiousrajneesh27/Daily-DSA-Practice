class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    int myAtoi(string s) {
        int i = 0;
        int num = 0;
        int sign = 1;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i < s.length()) {
            if (s[i] == '-') {
                sign = -1;
                i++;
            } else if (s[i] == '+') {
                i++;
            }
        }

        while (i < s.length() && isDigit(s[i])) {
            int digit = s[i] - '0';

            if (num > INT_MAX / 10 ||
               (num == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};
