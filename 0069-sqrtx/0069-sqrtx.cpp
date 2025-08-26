class Solution {
public:
    int mySqrt(int n) {
        int low = 0, high = n, ans = 0;
        while(low <= high) {
            long long mid = (low + high) / 2;
            long long val = (mid * mid);
            if(val <= n) {
                low = mid  +1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};