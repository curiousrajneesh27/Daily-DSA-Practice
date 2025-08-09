class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const long long MOD = 1'000'000'007LL;
        // If no bits are allowed, don't change a or b.
        if (n <= 0) {
            return (int)(((a % MOD) * (b % MOD)) % MOD);
        }

        // Start from the highest allowed bit (n-1) and go down to 0
        for (int i = n - 1; i >= 0; --i) {
            unsigned long long bit = 1ULL << i;
            if ((std::min(a, b) & bit) == 0) {
                a ^= bit;
                b ^= bit;
            }
        }

        return (int)(((a % MOD) * (b % MOD)) % MOD);
    }
};
