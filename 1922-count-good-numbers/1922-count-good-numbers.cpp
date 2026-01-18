class Solution {
public:
    static const long long MOD = 1000000007;

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenPow = 1, oddPow = 1;
        long long baseEven = 5, baseOdd = 4;

        while (even > 0) {
            if (even % 2 == 1)
                evenPow = (evenPow * baseEven) % MOD;
            baseEven = (baseEven * baseEven) % MOD;
            even /= 2;
        }

        while (odd > 0) {
            if (odd % 2 == 1)
                oddPow = (oddPow * baseOdd) % MOD;
            baseOdd = (baseOdd * baseOdd) % MOD;
            odd /= 2;
        }

        return (evenPow * oddPow) % MOD;
    }
};
