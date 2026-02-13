class Solution {
public:
    int divide(int dividend, int divisor) {

        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool sign = true;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = false;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long quotient = 0;

        while (n >= d) {
            long long cnt = 0;

            while (n >= (d << (cnt + 1))) {
                cnt++;
            }

            quotient += (1LL << cnt);
            n -= (d << cnt);
        }

        if (!sign) quotient = -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};
