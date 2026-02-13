class Solution {
public:
    int divide(int dividend, int divisor) {

        if (divisor == 0) return INT_MAX;   // added
        if (dividend == divisor) return 1;

        bool sign = true;
        if (dividend >= 0 && divisor < 0) sign = false;
        else if (dividend <= 0 && divisor > 0) sign = false;

        long long n = llabs((long long)dividend);  // fixed
        long long d = llabs((long long)divisor);   // fixed

        long long quotient = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += 1LL << cnt;   // fixed
            n -= (d << cnt);
        }

        if (quotient == (1LL << 31) && sign) {   // fixed
            return INT_MAX;
        }

        if (quotient == (1LL << 31) && !sign) {  // fixed
            return INT_MIN;
        }

        return sign ? quotient : -quotient;
    }
};
